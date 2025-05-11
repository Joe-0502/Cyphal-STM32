/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include <stdlib.h>
#include <string.h> // Needed for memcpy and strlen
#include "libcanard/canard.h"
#include "uavcan/node/Heartbeat_1_0.h"
#include "uavcan/node/GetInfo_1_0.h" // Already included, ensures request/response types are available
#include "uavcan/primitive/array/Real64_1_0.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
#define GETINFO_TARGET_NODE_ID 1 // Still used for *sending* GetInfo requests if needed

// Define this node's information for GetInfo responses
#define MY_NODE_NAME "org.stm32.12"
#define MY_HW_VERSION_MAJOR 0
#define MY_HW_VERSION_MINOR 1
#define MY_SW_VERSION_MAJOR 1
#define MY_SW_VERSION_MINOR 0
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
CAN_HandleTypeDef hcan1;

/* USER CODE BEGIN PV */
CanardInstance  canard;     // Libcanard instance
CanardTxQueue   queue;      // Transmission queue

static uint8_t getinfo_request_transfer_id = 0; // For *sending* requests
static uint8_t my_message_transfer_id = 0;      // For heartbeat messages
CanardPortID const MSG_PORT_ID = 1620U;         // Port for Real64 array messages
uint32_t test_uptimeSec = 0;

// Serialization buffer for Heartbeat
size_t hbeat_ser_buf_size = uavcan_node_Heartbeat_1_0_EXTENT_BYTES_;
uint8_t hbeat_ser_buf[uavcan_node_Heartbeat_1_0_EXTENT_BYTES_];

// --- GetInfo Request Sending ---
uint8_t getinfo_request_ser_buf[1]; // Buffer for *sending* GetInfo requests (empty payload)
size_t getinfo_request_ser_buf_size = sizeof(getinfo_request_ser_buf);

// --- GetInfo Response Handling ---
// Buffer for serializing GetInfo *responses* sent by this node
// Make it static if used only within the callback, or global/static global if accessed elsewhere
static uint8_t getinfo_response_ser_buf[uavcan_node_GetInfo_Response_1_0_EXTENT_BYTES_];
size_t getinfo_response_ser_buf_size = sizeof(getinfo_response_ser_buf);

// Subscription states (optional to store them if not needed later, but good practice)
CanardRxSubscription heartbeat_subscription; // Example if subscribing to heartbeats
CanardRxSubscription real64_subscription;
CanardRxSubscription getinfo_request_subscription; // For incoming GetInfo requests

volatile bool is_can_tx_pending = false;
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_CAN1_Init(void);
/* USER CODE BEGIN PFP */
// Wrappers for using o1heap allocator with libcanard
static void* memAllocate(CanardInstance* const ins, const size_t amount);
static void memFree(CanardInstance* const ins, void* const pointer);

// Application-specific function prototypes
void process_canard_TX_queue(void);
void handle_received_transfer(CanardRxTransfer* transfer); // Function to process accepted transfers

// --- Add function to get Unique ID ---
// Placeholder - Implement this using HAL_GetUIDw0(), HAL_GetUIDw1(), HAL_GetUIDw2()
void get_unique_id(uint8_t* unique_id_buffer); // Takes a 16-byte buffer

// return useconds - !! IMPORTANT: NEEDS REAL IMPLEMENTATION !!
uint64_t micros(void) // Changed to uint64_t for standard libcanard usage
{
  // Replace with HAL_GetTick() or preferably a hardware timer (e.g., TIM) based microsecond counter
  // Example using HAL_GetTick() (millisecond resolution, multiply by 1000)
  // return (uint64_t)HAL_GetTick() * 1000ULL;
  // For now, returning 0 - THIS WILL CAUSE ISSUES WITH TIMEOUTS
  return 0;
}
/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
// Placeholder implementation for unique ID
void get_unique_id(uint8_t* unique_id_buffer) {
    // On STM32, the unique ID is typically 96 bits (12 bytes)
    // The GetInfo response expects 128 bits (16 bytes)
    // Read the 12 bytes using HAL functions and pad the rest (e.g., with zeros)
    memset(unique_id_buffer, 0, 16); // Clear buffer first

    // Example using HAL functions (Check your specific STM32 reference manual for base address)
    // uint32_t uid_w0 = HAL_GetUIDw0(); // Read UID word 0
    // uint32_t uid_w1 = HAL_GetUIDw1(); // Read UID word 1
    // uint32_t uid_w2 = HAL_GetUIDw2(); // Read UID word 2
    // memcpy(unique_id_buffer + 0, &uid_w0, sizeof(uid_w0));
    // memcpy(unique_id_buffer + 4, &uid_w1, sizeof(uid_w1));
    // memcpy(unique_id_buffer + 8, &uid_w2, sizeof(uid_w2));
    // The remaining 4 bytes are left as 0

    // --- For testing without HAL ---
    // Fill with a dummy pattern if HAL_GetUID isn't available/implemented yet
    for (int i = 0; i < 16; ++i) {
        unique_id_buffer[i] = (uint8_t)(i + 1); // Example dummy pattern
    }
}
/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{

  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_CAN1_Init();
  /* USER CODE BEGIN 2 */
  HAL_CAN_Start(&hcan1);
  if (HAL_CAN_ActivateNotification(&hcan1, CAN_IT_RX_FIFO0_MSG_PENDING | CAN_IT_TX_MAILBOX_EMPTY) != HAL_OK)
  {
      Error_Handler();
  }
  CAN_FilterTypeDef Filter;
  Filter.FilterIdHigh = 0x0000;
  Filter.FilterIdLow = 0x0000;
  Filter.FilterMaskIdHigh = 0x0000;
  Filter.FilterMaskIdLow = 0x0000;
  Filter.FilterFIFOAssignment = CAN_RX_FIFO0;
  Filter.FilterBank = 0;
  Filter.FilterMode = CAN_FILTERMODE_IDMASK;
  Filter.FilterScale = CAN_FILTERSCALE_32BIT;
  Filter.FilterActivation = ENABLE;
  Filter.SlaveStartFilterBank = 0;
  HAL_CAN_ConfigFilter(&hcan1, &Filter);

  // Initialize Libcanard
  canard = canardInit(&memAllocate, &memFree);
  canard.node_id = 5; // This node's ID

  // Initialize the TX queue
  queue = canardTxInit(100, CANARD_MTU_CAN_CLASSIC);

  // --- Subscribe to incoming Real64 array messages ---
  if (canardRxSubscribe((CanardInstance* const)&canard,
                        CanardTransferKindMessage,
                        MSG_PORT_ID, // 1620U
                        uavcan_primitive_array_Real64_1_0_EXTENT_BYTES_,
                        CANARD_DEFAULT_TRANSFER_ID_TIMEOUT_USEC,
                        &real64_subscription) != 1) // Store subscription state
  {
      Error_Handler(); // Failed to subscribe
  }

  // --- Subscribe to incoming uavcan.node.GetInfo requests ---
  // We want to *receive* requests for this service
  if (canardRxSubscribe((CanardInstance* const)&canard,
                        CanardTransferKindRequest, // *** We are listening for REQUESTS ***
                        uavcan_node_GetInfo_1_0_FIXED_PORT_ID_, // Fixed Port ID for GetInfo
                        uavcan_node_GetInfo_Request_1_0_EXTENT_BYTES_, // Max size of request payload (0)
                        CANARD_DEFAULT_TRANSFER_ID_TIMEOUT_USEC,
                        &getinfo_request_subscription) != 1) // Store subscription state
   {
       Error_Handler(); // Failed to subscribe
   }

  // --- Optional: Subscribe to Heartbeats from other nodes (Example) ---
  // if( canardRxSubscribe((CanardInstance* const)&canard,
  //                       CanardTransferKindMessage,
  //                       uavcan_node_Heartbeat_1_0_FIXED_PORT_ID_,
  //                       uavcan_node_Heartbeat_1_0_EXTENT_BYTES_,
  //                       CANARD_DEFAULT_TRANSFER_ID_TIMEOUT_USEC,
  //                       &heartbeat_subscription) != 1)
  // {
  //     Error_Handler();
  // }

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {

      // --- Publish Heartbeat ---
      uavcan_node_Heartbeat_1_0 test_heartbeat = {
          .uptime = test_uptimeSec,
          .health = {uavcan_node_Health_1_0_NOMINAL},
          .mode = {uavcan_node_Mode_1_0_OPERATIONAL}
      };
      hbeat_ser_buf_size = uavcan_node_Heartbeat_1_0_EXTENT_BYTES_; // Reset size before serializing
      if (uavcan_node_Heartbeat_1_0_serialize_(&test_heartbeat, hbeat_ser_buf, &hbeat_ser_buf_size) >= 0)
      {
          const CanardTransferMetadata transfer_metadata = {
              .priority = CanardPriorityNominal,
              .transfer_kind = CanardTransferKindMessage,
              .port_id = uavcan_node_Heartbeat_1_0_FIXED_PORT_ID_,
              .remote_node_id = CANARD_NODE_ID_UNSET, // Broadcast
              .transfer_id = my_message_transfer_id,
          };
          canardTxPush(&queue, &canard, 0, &transfer_metadata, hbeat_ser_buf_size, hbeat_ser_buf);
          my_message_transfer_id++; // Increment only if push is attempted (or successful)
      } else {
          // Serialization error
          Error_Handler();
      }


      /*
      // --- Publish Getinfo request ---
       if ((test_uptimeSec % 10 == 1) && (test_uptimeSec > 0)) // Send every 10 seconds approx.
       {
           uavcan_node_GetInfo_Request_1_0 getinfo_req = {0}; // Empty request
           getinfo_request_ser_buf_size = sizeof(getinfo_request_ser_buf); // Reset size
           if (uavcan_node_GetInfo_Request_1_0_serialize_(&getinfo_req, getinfo_request_ser_buf, &getinfo_request_ser_buf_size) >= 0)
           {
               // Ensure payload size is actually 0 after serialization
               if (getinfo_request_ser_buf_size == 0) {
                   const CanardTransferMetadata getinfo_req_metadata = {
                       .priority = CanardPriorityNominal,
                       .transfer_kind = CanardTransferKindRequest, // Sending a request
                       .port_id = uavcan_node_GetInfo_1_0_FIXED_PORT_ID_,
                       .remote_node_id = GETINFO_TARGET_NODE_ID, // Target node ID
                       .transfer_id = getinfo_request_transfer_id,
                   };
                   if (canardTxPush(&queue, &canard, 0, &getinfo_req_metadata, getinfo_request_ser_buf_size, getinfo_request_ser_buf) >= 0)
                   {
                       getinfo_request_transfer_id++; // Increment *after* successful push
                   }
                   // else: Handle push error (e.g., log)
               } else {
                    // Serialization resulted in non-zero size for empty request? Error.
                    Error_Handler();
               }
           } else {
               // Serialization error
               Error_Handler();
           }
       }
		*/

      // --- Process TX Queue and Delay ---
      uint32_t timestamp = HAL_GetTick();
      while (HAL_GetTick() < timestamp + 1000u)
      {
          process_canard_TX_queue();
          // Check for received frames periodically within the delay
          // The interrupt handler HAL_CAN_RxFifo0MsgPendingCallback will process incoming frames
          HAL_Delay(10); // Yield CPU
      }

      test_uptimeSec++; // Increment uptime

    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  if (HAL_PWREx_ControlVoltageScaling(PWR_REGULATOR_VOLTAGE_SCALE1) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_MSI;
  RCC_OscInitStruct.MSIState = RCC_MSI_ON;
  RCC_OscInitStruct.MSICalibrationValue = 0;
  RCC_OscInitStruct.MSIClockRange = RCC_MSIRANGE_6;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_MSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief CAN1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_CAN1_Init(void)
{

  /* USER CODE BEGIN CAN1_Init 0 */

  /* USER CODE END CAN1_Init 0 */

  /* USER CODE BEGIN CAN1_Init 1 */

  /* USER CODE END CAN1_Init 1 */
  hcan1.Instance = CAN1;
  // Baud rate calculation: Clock/(SyncJumpWidth+TimeSeg1+TimeSeg2)/Prescaler
  // Assuming System Clock is 4MHz (MSI Range 6 default)
  // 4MHz / (1+13+2) / 1 = 4MHz / 16 / 1 = 250 kbit/s
  // Adjust Prescaler if clock is different or different baud rate needed
  hcan1.Init.Prescaler = 1;
  hcan1.Init.Mode = CAN_MODE_NORMAL;
  hcan1.Init.SyncJumpWidth = CAN_SJW_1TQ;
  hcan1.Init.TimeSeg1 = CAN_BS1_13TQ;
  hcan1.Init.TimeSeg2 = CAN_BS2_2TQ;
  hcan1.Init.TimeTriggeredMode = DISABLE;
  hcan1.Init.AutoBusOff = DISABLE; // Consider enabling for robustness
  hcan1.Init.AutoWakeUp = DISABLE;
  hcan1.Init.AutoRetransmission = DISABLE; // Cyphal handles retransmission at transfer layer if needed
  hcan1.Init.ReceiveFifoLocked = DISABLE; // Allow overwrite on overrun
  hcan1.Init.TransmitFifoPriority = ENABLE;
  if (HAL_CAN_Init(&hcan1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN CAN1_Init 2 */

  /* USER CODE END CAN1_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};
/* USER CODE BEGIN MX_GPIO_Init_1 */
/* USER CODE END MX_GPIO_Init_1 */

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOA_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_RESET); // Assuming PA5 is LED

  /*Configure GPIO pin : PA5 */
  GPIO_InitStruct.Pin = GPIO_PIN_5;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);


/* USER CODE BEGIN MX_GPIO_Init_2 */
/* USER CODE END MX_GPIO_Init_2 */
}

/* USER CODE BEGIN 4 */
void HAL_CAN_TxMailbox0CompleteCallback(CAN_HandleTypeDef *hcan)
{
    if (hcan->Instance == CAN1) {
        if (is_can_tx_pending) { // 確保我們確實有一個待處理的發送
            const CanardTxQueueItem* ti = canardTxPeek(&queue);
            if (ti != NULL) { // 確保 Libcanard 佇列的隊首確實有幀
                canard.memory_free(&canard, canardTxPop(&queue, ti));
            }
            is_can_tx_pending = false; // 清除標誌，允許 process_canard_TX_queue 發送下一個
        }
        // 可選：如果您的應用響應非常快，可以在這裡嘗試調用 process_canard_TX_queue()
        // 但通常在主循環中調用更安全，以避免中斷風暴或棧溢出。
        // process_canard_TX_queue();
    }
}

void HAL_CAN_TxMailbox1CompleteCallback(CAN_HandleTypeDef *hcan)
{
    if (hcan->Instance == CAN1) {
        if (is_can_tx_pending) {
            const CanardTxQueueItem* ti = canardTxPeek(&queue);
            if (ti != NULL) {
                canard.memory_free(&canard, canardTxPop(&queue, ti));
            }
            is_can_tx_pending = false;
        }
    }
}

void HAL_CAN_TxMailbox2CompleteCallback(CAN_HandleTypeDef *hcan)
{
    if (hcan->Instance == CAN1) {
        if (is_can_tx_pending) {
            const CanardTxQueueItem* ti = canardTxPeek(&queue);
            if (ti != NULL) {
                canard.memory_free(&canard, canardTxPop(&queue, ti));
            }
            is_can_tx_pending = false;
        }
    }
}
// Function to process the TX queue
void process_canard_TX_queue(void)
{
    // 關鍵：只有在沒有幀正在等待硬體發送 (is_can_tx_pending == false)
    // 並且硬體至少有一個空閒信箱時，才嘗試從 Libcanard 佇列取幀並提交。
    if (!is_can_tx_pending && (HAL_CAN_GetTxMailboxesFreeLevel(&hcan1) > 0))
    {
        const CanardTxQueueItem* ti = canardTxPeek(&queue);
        if (ti != NULL)
        {
            // 可以添加截止時間檢查 (需要 micros() 正常工作)
            // if ((0U == ti->tx_deadline_usec) || (ti->tx_deadline_usec > micros()))

            CAN_TxHeaderTypeDef TxHeader;
            TxHeader.IDE = CAN_ID_EXT;
            TxHeader.RTR = CAN_RTR_DATA;
            TxHeader.DLC = ti->frame.payload_size;
            TxHeader.ExtId = ti->frame.extended_can_id;
            TxHeader.TransmitGlobalTime = DISABLE;

            if (ti->frame.payload_size <= 8) {
                // 嘗試將幀添加到硬體 TX 信箱
                if (HAL_CAN_AddTxMessage(&hcan1, &TxHeader, (uint8_t*)ti->frame.payload, NULL) == HAL_OK)
                {
                    // 成功提交給硬體
                    is_can_tx_pending = true; // 標記一個幀已提交，等待 TX 完成中斷
                                             // 不要在此處 Pop，TX 完成中斷會處理
                }
                // else: HAL_CAN_AddTxMessage 失敗
                // is_can_tx_pending 仍然是 false，會在下一次調用時重試
            } else {
                // 負載大小錯誤
                canard.memory_free(&canard, canardTxPop(&queue, ti)); // 丟棄無效幀
                // 記錄錯誤
            }
            // else: Deadline expired
            // {
            //    canard.memory_free(&canard, canardTxPop(&queue, ti));
            // }
        }
    }
}



// Central handler for successfully received transfers from canardRxAccept
void handle_received_transfer(CanardRxTransfer* transfer)
{
    // --- Handle GetInfo Request ---
    if (transfer->metadata.transfer_kind == CanardTransferKindRequest &&
        transfer->metadata.port_id == uavcan_node_GetInfo_1_0_FIXED_PORT_ID_)
    {
        // Received a GetInfo request targeted at us (or broadcast)

        // 1. (Optional) Deserialize the request payload (it should be empty)
        uavcan_node_GetInfo_Request_1_0 req;
        size_t req_payload_size = transfer->payload_size;
        if (uavcan_node_GetInfo_Request_1_0_deserialize_(&req, transfer->payload, &req_payload_size) < 0) {
            // Deserialization failed (though payload is empty, this check might catch framing issues)
            // Log error, but maybe still proceed to respond? Or ignore.
        }

        // 2. Prepare the response payload
        uavcan_node_GetInfo_Response_1_0 response = {0}; // Initialize all fields to zero/empty

        // -- Populate mandatory fields --
        response.protocol_version.major = CANARD_CYPHAL_SPECIFICATION_VERSION_MAJOR;
        response.protocol_version.minor = CANARD_CYPHAL_SPECIFICATION_VERSION_MINOR;

        response.hardware_version.major = MY_HW_VERSION_MAJOR;
        response.hardware_version.minor = MY_HW_VERSION_MINOR;

        response.software_version.major = MY_SW_VERSION_MAJOR;
        response.software_version.minor = MY_SW_VERSION_MINOR;

        // -- Populate optional fields --
        response.software_vcs_revision_id = 0; // Or use actual Git commit hash ID if available

        get_unique_id(response.unique_id); // Fill the 16-byte unique ID array

        // Set the node name (ensure null termination and check length)
        const char* src_node_name = MY_NODE_NAME;
        size_t name_len = strlen(src_node_name);
        //response.name.elements[sizeof(response.name.elements) - 1] = '\0'; // Ensure null termination
        if (name_len > sizeof(response.name.elements)) {
            name_len = sizeof(response.name.elements); // 如果源名稱太長，則截斷
        }
        memcpy(response.name.elements, src_node_name, name_len);
        response.name.count = (uint8_t)name_len;

        // software_image_crc and certificate_of_authenticity are optional
        response.software_image_crc.count = 0; // No CRC available
        response.certificate_of_authenticity.count = 0; // No CoA available


        // 3. Serialize the response
        getinfo_response_ser_buf_size = sizeof(getinfo_response_ser_buf); // Reset size before use
        int8_t ser_res = uavcan_node_GetInfo_Response_1_0_serialize_(&response, getinfo_response_ser_buf, &getinfo_response_ser_buf_size);

        if (ser_res >= 0)
        {
            // 4. Prepare response metadata
            CanardTransferMetadata response_metadata = {
                .priority = CanardPriorityNominal, // Respond with nominal priority
                .transfer_kind = CanardTransferKindResponse, // *** This is a RESPONSE ***
                .port_id = uavcan_node_GetInfo_1_0_FIXED_PORT_ID_, // Use the same service Port ID
                .remote_node_id = transfer->metadata.remote_node_id, // *** Respond TO the requester ***
                .transfer_id = transfer->metadata.transfer_id, // *** Use the SAME transfer ID ***
            };

            // 5. Push response to the TX queue
            canardTxPush(&queue, &canard, 0, &response_metadata, getinfo_response_ser_buf_size, getinfo_response_ser_buf);

            // Ignore push errors for now, or log them
        }
        else
        {
            // Response serialization failed
            // Log error
        	Error_Handler();
        }
    }
    // --- Handle Real64 Array Message ---
    else if (transfer->metadata.transfer_kind == CanardTransferKindMessage &&
             transfer->metadata.port_id == MSG_PORT_ID) // 1620U
    {
        uavcan_primitive_array_Real64_1_0 array;
        size_t array_ser_buf_size = transfer->payload_size; // Use actual received size for deserialization

        if (uavcan_primitive_array_Real64_1_0_deserialize_(&array, transfer->payload, &array_ser_buf_size) >= 0)
        {
            // Successfully deserialized - process the 'array' data here
            // Example: Toggle LED
            HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_5);
        }
        else
        {
            // Deserialization failed for the Real64 array
            // Log error
        }
    }
    // --- Handle other subscribed transfers if any ---
    // else if (transfer->metadata.transfer_kind == ... && transfer->metadata.port_id == ...) {
    //    // Handle other messages/services
    // }
    else
    {
        // Received a transfer that was accepted by canardRxAccept but doesn't match known handlers
        // This shouldn't happen if subscriptions are set up correctly for expected types.
        // Log warning?
    }

    // --- IMPORTANT: Free the received payload buffer ---
    // Must be done for ALL successfully accepted transfers handled here
    canard.memory_free(&canard, transfer->payload);
}


//#pragma optimize=s none // Keep optimization low for ISR debugging if needed
#pragma optimize=s none // 可以移除或註解掉這一行
void HAL_CAN_RxFifo0MsgPendingCallback(CAN_HandleTypeDef *hcan)
{
    if (hcan->Instance == CAN1) // Check if the interrupt is for the correct CAN instance
    {
        CAN_RxHeaderTypeDef RxHeader;
        uint8_t RxData[8]; // Max payload for Classic CAN

        if (HAL_CAN_GetRxMessage(hcan, CAN_RX_FIFO0, &RxHeader, RxData) == HAL_OK)
        {
            // Check if it's an Extended ID frame (Cyphal uses Extended IDs)
            if (RxHeader.IDE == CAN_ID_EXT)
            {
                CanardFrame rxf;
                // rxf.timestamp_usec = micros(); // !! REMOVE THIS LINE !!

                // Populate the CanardFrame structure without the timestamp
                rxf.extended_can_id = RxHeader.ExtId;
                rxf.payload_size = (size_t)RxHeader.DLC;
                rxf.payload = (void*)RxData;

                CanardRxTransfer transfer;
                CanardMicrosecond timestamp = micros(); // !! Get timestamp here !!

                // --- CORRECTED CALL to canardRxAccept ---
                int8_t accept_res = canardRxAccept(&canard,        // 1. Instance
                                                   timestamp,      // 2. Timestamp (uint64_t)
                                                   &rxf,           // 3. Frame pointer (const CanardFrame*)
                                                   0,              // 4. Redundant interface index (uint8_t)
                                                   &transfer,      // 5. Output transfer pointer (CanardRxTransfer*)
                                                   NULL);          // 6. Output subscription pointer (CanardRxSubscription**) - NULL if not needed

                if (accept_res == 1) // A complete transfer has been received
                {
                    // Call the central handler function
                    handle_received_transfer(&transfer);
                }
                else if (accept_res < 0) // An error occurred during reception (e.g., OOM)
                {
                    // Handle reception error (e.g., log, reset state?)
                    // Consider freeing potential partial payloads if Libcanard requires it on error. Check docs.
                }
                // else: accept_res == 0 (Frame accepted, but transfer not complete yet) - Do nothing
            }
            // else: Standard ID frame - Ignore for Cyphal
        }
        // else: HAL_CAN_GetRxMessage failed - Handle error (e.g., log)
    }
}




// --- Memory Allocator Wrappers ---
static void* memAllocate(CanardInstance* const ins, const size_t amount)
{
    (void) ins;
    return malloc(amount);
}

static void memFree(CanardInstance* const ins, void* const pointer)
{
    (void) ins;
    free(pointer);
}
/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  // Maybe flash LED rapidly or send error over another interface
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
