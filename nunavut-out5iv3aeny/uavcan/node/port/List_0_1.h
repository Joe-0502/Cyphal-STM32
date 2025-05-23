// This is an AUTO-GENERATED Cyphal DSDL data type implementation. Curious? See https://opencyphal.org.
// You shouldn't attempt to edit this file.
//
// Checking this file under version control is not recommended unless it is used as part of a high-SIL
// safety-critical codebase. The typical usage scenario is to generate it as part of the build process.
//
// To avoid conflicts with definitions given in the source DSDL file, all entities created by the code generator
// are named with an underscore at the end, like foo_bar_().
//
// Generator:     nunavut-2.3.1 (serialization was enabled)
// Source file:   /tmp/pyuavcan-cli-dsdl6mzrytyr/public_regulated_data_types-master/uavcan/node/port/7510.List.0.1.dsdl
// Generated at:  2025-04-15 13:30:24.385136 UTC
// Is deprecated: yes
// Fixed port-ID: 7510
// Full name:     uavcan.node.port.List
// Version:       0.1
//
// Platform
//     python_implementation:  CPython
//     python_version:  3.9.1
//     python_release_level:  final
//     python_build:  ('default', 'Feb  9 2021 07:55:26')
//     python_compiler:  GCC 8.3.0
//     python_revision:
//     python_xoptions:  {}
//     runtime_platform:  Linux-5.4.0-212-generic-x86_64-with-glibc2.28
//
// Language Options
//     target_endianness:  little
//     omit_float_serialization_support:  False
//     enable_serialization_asserts:  True
//     enable_override_variable_array_capacity:  False
//     cast_format:  (({type}) {value})

//           _____  ______ _____  _____  ______ _____       _______ ______ _____
//          |  __ `|  ____|  __ `|  __ `|  ____/ ____|   /`|__   __|  ____|  __ `
//          | |  | | |__  | |__) | |__) | |__ | |       /  `  | |  | |__  | |  | |
//          | |  | |  __| |  ___/|  _  /|  __|| |      / /` ` | |  |  __| | |  | |
//          | |__| | |____| |    | | ` `| |___| |____ / ____ `| |  | |____| |__| |
//          |_____/|______|_|    |_|  `_`______`_____/_/    `_`_|  |______|_____/
//
// WARNING: this data type is deprecated and is nearing the end of its life cycle. Seek replacement.

#ifndef UAVCAN_NODE_PORT_LIST_0_1_INCLUDED_
#define UAVCAN_NODE_PORT_LIST_0_1_INCLUDED_

#include <nunavut/support/serialization.h>
#include <stdint.h>
#include <stdlib.h>
#include <uavcan/node/port/ServiceIDList_0_1.h>
#include <uavcan/node/port/SubjectIDList_0_1.h>

static_assert( NUNAVUT_SUPPORT_LANGUAGE_OPTION_TARGET_ENDIANNESS == 434322821,
              "/tmp/pyuavcan-cli-dsdl6mzrytyr/public_regulated_data_types-master/uavcan/node/port/7510.List.0.1.dsdl is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not allowed." );
static_assert( NUNAVUT_SUPPORT_LANGUAGE_OPTION_OMIT_FLOAT_SERIALIZATION_SUPPORT == 0,
              "/tmp/pyuavcan-cli-dsdl6mzrytyr/public_regulated_data_types-master/uavcan/node/port/7510.List.0.1.dsdl is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not allowed." );
static_assert( NUNAVUT_SUPPORT_LANGUAGE_OPTION_ENABLE_SERIALIZATION_ASSERTS == 1,
              "/tmp/pyuavcan-cli-dsdl6mzrytyr/public_regulated_data_types-master/uavcan/node/port/7510.List.0.1.dsdl is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not allowed." );
static_assert( NUNAVUT_SUPPORT_LANGUAGE_OPTION_ENABLE_OVERRIDE_VARIABLE_ARRAY_CAPACITY == 0,
              "/tmp/pyuavcan-cli-dsdl6mzrytyr/public_regulated_data_types-master/uavcan/node/port/7510.List.0.1.dsdl is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not allowed." );
static_assert( NUNAVUT_SUPPORT_LANGUAGE_OPTION_CAST_FORMAT == 2368206204,
              "/tmp/pyuavcan-cli-dsdl6mzrytyr/public_regulated_data_types-master/uavcan/node/port/7510.List.0.1.dsdl is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not allowed." );

#ifdef __cplusplus
extern "C" {
#endif

#define uavcan_node_port_List_0_1_HAS_FIXED_PORT_ID_ true
#define uavcan_node_port_List_0_1_FIXED_PORT_ID_     7510U

// +-------------------------------------------------------------------------------------------------------------------+
// | uavcan.node.port.List.0.1
// +-------------------------------------------------------------------------------------------------------------------+
#define uavcan_node_port_List_0_1_FULL_NAME_             "uavcan.node.port.List"
#define uavcan_node_port_List_0_1_FULL_NAME_AND_VERSION_ "uavcan.node.port.List.0.1"

/// Extent is the minimum amount of memory required to hold any serialized representation of any compatible
/// version of the data type; or, on other words, it is the the maximum possible size of received objects of this type.
/// The size is specified in bytes (rather than bits) because by definition, extent is an integer number of bytes long.
/// When allocating a deserialization (RX) buffer for this data type, it should be at least extent bytes large.
/// When allocating a serialization (TX) buffer, it is safe to use the size of the largest serialized representation
/// instead of the extent because it provides a tighter bound of the object size; it is safe because the concrete type
/// is always known during serialization (unlike deserialization). If not sure, use extent everywhere.
#define uavcan_node_port_List_0_1_EXTENT_BYTES_                    8466UL
#define uavcan_node_port_List_0_1_SERIALIZATION_BUFFER_SIZE_BYTES_ 8466UL
static_assert(uavcan_node_port_List_0_1_EXTENT_BYTES_ >= uavcan_node_port_List_0_1_SERIALIZATION_BUFFER_SIZE_BYTES_,
              "Internal constraint violation");

/// saturated uint8 MAX_PUBLICATION_PERIOD = 10
#define uavcan_node_port_List_0_1_MAX_PUBLICATION_PERIOD (10U)

typedef struct
{
    /// uavcan.node.port.SubjectIDList.0.1 publishers
    uavcan_node_port_SubjectIDList_0_1 publishers;

    /// uavcan.node.port.SubjectIDList.0.1 subscribers
    uavcan_node_port_SubjectIDList_0_1 subscribers;

    /// uavcan.node.port.ServiceIDList.0.1 clients
    uavcan_node_port_ServiceIDList_0_1 clients;

    /// uavcan.node.port.ServiceIDList.0.1 servers
    uavcan_node_port_ServiceIDList_0_1 servers;
} uavcan_node_port_List_0_1;

/// Serialize an instance into the provided buffer.
/// The lifetime of the resulting serialized representation is independent of the original instance.
/// This method may be slow for large objects (e.g., images, point clouds, radar samples), so in a later revision
/// we may define a zero-copy alternative that keeps references to the original object where possible.
///
/// @param obj      The object to serialize.
///
/// @param buffer   The destination buffer. There are no alignment requirements.
///                 @see uavcan_node_port_List_0_1_SERIALIZATION_BUFFER_SIZE_BYTES_
///
/// @param inout_buffer_size_bytes  When calling, this is a pointer to the size of the buffer in bytes.
///                                 Upon return this value will be updated with the size of the constructed serialized
///                                 representation (in bytes); this value is then to be passed over to the transport
///                                 layer. In case of error this value is undefined.
///
/// @returns Negative on error, zero on success.
static inline int8_t uavcan_node_port_List_0_1_serialize_(
    const uavcan_node_port_List_0_1* const obj, uint8_t* const buffer,  size_t* const inout_buffer_size_bytes)
{
    if ((obj == NULL) || (buffer == NULL) || (inout_buffer_size_bytes == NULL))
    {
        return -NUNAVUT_ERROR_INVALID_ARGUMENT;
    }
    const size_t capacity_bytes = *inout_buffer_size_bytes;
    if ((8U * (size_t) capacity_bytes) < 67728UL)
    {
        return -NUNAVUT_ERROR_SERIALIZATION_BUFFER_TOO_SMALL;
    }
    // Notice that fields that are not an integer number of bytes long may overrun the space allocated for them
    // in the serialization buffer up to the next byte boundary. This is by design and is guaranteed to be safe.
    size_t offset_bits = 0U;
    {   // uavcan.node.port.SubjectIDList.0.1 publishers
        NUNAVUT_ASSERT(offset_bits % 8U == 0U);
        NUNAVUT_ASSERT(offset_bits % 8U == 0U);
        NUNAVUT_ASSERT((offset_bits + 32808ULL) <= (capacity_bytes * 8U));
        size_t _size_bytes0_ = 1025UL;  // Nested object (max) size, in bytes.
        offset_bits += 32U;  // Reserve space for the delimiter header.
        NUNAVUT_ASSERT(offset_bits % 8U == 0U);
        NUNAVUT_ASSERT((offset_bits / 8U + _size_bytes0_) <= capacity_bytes);
        int8_t _err0_ = uavcan_node_port_SubjectIDList_0_1_serialize_(
            &obj->publishers, &buffer[offset_bits / 8U], &_size_bytes0_);
        if (_err0_ < 0)
        {
            return _err0_;
        }
        // It is assumed that we know the exact type of the serialized entity, hence we expect the size to match.
        NUNAVUT_ASSERT((_size_bytes0_ * 8U) >= 8ULL);
        NUNAVUT_ASSERT((_size_bytes0_ * 8U) <= 8200ULL);
        // Jump back to write the delimiter header after the nested object is serialized and its length is known.
        (void) memmove(&buffer[(offset_bits - 32) / 8U], &_size_bytes0_, 4U);
        offset_bits += _size_bytes0_ * 8U;  // Advance by the size of the nested object.
        NUNAVUT_ASSERT(offset_bits <= (capacity_bytes * 8U));
    }
    if (offset_bits % 8U != 0U)  // Pad to 8 bits. TODO: Eliminate redundant padding checks.
    {
        const uint8_t _pad0_ = (uint8_t)(8U - offset_bits % 8U);
        NUNAVUT_ASSERT(_pad0_ > 0);
        const int8_t _err1_ = nunavutSetUxx(&buffer[0], capacity_bytes, offset_bits, 0U, _pad0_);  // Optimize?
        if (_err1_ < 0)
        {
            return _err1_;
        }
        offset_bits += _pad0_;
        NUNAVUT_ASSERT(offset_bits % 8U == 0U);
    }
    {   // uavcan.node.port.SubjectIDList.0.1 subscribers
        NUNAVUT_ASSERT(offset_bits % 8U == 0U);
        NUNAVUT_ASSERT(offset_bits % 8U == 0U);
        NUNAVUT_ASSERT((offset_bits + 32808ULL) <= (capacity_bytes * 8U));
        size_t _size_bytes1_ = 1025UL;  // Nested object (max) size, in bytes.
        offset_bits += 32U;  // Reserve space for the delimiter header.
        NUNAVUT_ASSERT(offset_bits % 8U == 0U);
        NUNAVUT_ASSERT((offset_bits / 8U + _size_bytes1_) <= capacity_bytes);
        int8_t _err2_ = uavcan_node_port_SubjectIDList_0_1_serialize_(
            &obj->subscribers, &buffer[offset_bits / 8U], &_size_bytes1_);
        if (_err2_ < 0)
        {
            return _err2_;
        }
        // It is assumed that we know the exact type of the serialized entity, hence we expect the size to match.
        NUNAVUT_ASSERT((_size_bytes1_ * 8U) >= 8ULL);
        NUNAVUT_ASSERT((_size_bytes1_ * 8U) <= 8200ULL);
        // Jump back to write the delimiter header after the nested object is serialized and its length is known.
        (void) memmove(&buffer[(offset_bits - 32) / 8U], &_size_bytes1_, 4U);
        offset_bits += _size_bytes1_ * 8U;  // Advance by the size of the nested object.
        NUNAVUT_ASSERT(offset_bits <= (capacity_bytes * 8U));
    }
    if (offset_bits % 8U != 0U)  // Pad to 8 bits. TODO: Eliminate redundant padding checks.
    {
        const uint8_t _pad1_ = (uint8_t)(8U - offset_bits % 8U);
        NUNAVUT_ASSERT(_pad1_ > 0);
        const int8_t _err3_ = nunavutSetUxx(&buffer[0], capacity_bytes, offset_bits, 0U, _pad1_);  // Optimize?
        if (_err3_ < 0)
        {
            return _err3_;
        }
        offset_bits += _pad1_;
        NUNAVUT_ASSERT(offset_bits % 8U == 0U);
    }
    {   // uavcan.node.port.ServiceIDList.0.1 clients
        NUNAVUT_ASSERT(offset_bits % 8U == 0U);
        NUNAVUT_ASSERT(offset_bits % 8U == 0U);
        NUNAVUT_ASSERT((offset_bits + 1056ULL) <= (capacity_bytes * 8U));
        size_t _size_bytes2_ = 64UL;  // Nested object (max) size, in bytes.
        // Constant delimiter header can be written ahead of the nested object.
        (void) memmove(&buffer[offset_bits / 8U], &_size_bytes2_, 4U);
        offset_bits += 32U;
        NUNAVUT_ASSERT(offset_bits % 8U == 0U);
        NUNAVUT_ASSERT((offset_bits / 8U + _size_bytes2_) <= capacity_bytes);
        int8_t _err4_ = uavcan_node_port_ServiceIDList_0_1_serialize_(
            &obj->clients, &buffer[offset_bits / 8U], &_size_bytes2_);
        if (_err4_ < 0)
        {
            return _err4_;
        }
        // It is assumed that we know the exact type of the serialized entity, hence we expect the size to match.
        NUNAVUT_ASSERT((_size_bytes2_ * 8U) == 512ULL);
        offset_bits += _size_bytes2_ * 8U;  // Advance by the size of the nested object.
        NUNAVUT_ASSERT(offset_bits <= (capacity_bytes * 8U));
    }
    if (offset_bits % 8U != 0U)  // Pad to 8 bits. TODO: Eliminate redundant padding checks.
    {
        const uint8_t _pad2_ = (uint8_t)(8U - offset_bits % 8U);
        NUNAVUT_ASSERT(_pad2_ > 0);
        const int8_t _err5_ = nunavutSetUxx(&buffer[0], capacity_bytes, offset_bits, 0U, _pad2_);  // Optimize?
        if (_err5_ < 0)
        {
            return _err5_;
        }
        offset_bits += _pad2_;
        NUNAVUT_ASSERT(offset_bits % 8U == 0U);
    }
    {   // uavcan.node.port.ServiceIDList.0.1 servers
        NUNAVUT_ASSERT(offset_bits % 8U == 0U);
        NUNAVUT_ASSERT(offset_bits % 8U == 0U);
        NUNAVUT_ASSERT((offset_bits + 1056ULL) <= (capacity_bytes * 8U));
        size_t _size_bytes3_ = 64UL;  // Nested object (max) size, in bytes.
        // Constant delimiter header can be written ahead of the nested object.
        (void) memmove(&buffer[offset_bits / 8U], &_size_bytes3_, 4U);
        offset_bits += 32U;
        NUNAVUT_ASSERT(offset_bits % 8U == 0U);
        NUNAVUT_ASSERT((offset_bits / 8U + _size_bytes3_) <= capacity_bytes);
        int8_t _err6_ = uavcan_node_port_ServiceIDList_0_1_serialize_(
            &obj->servers, &buffer[offset_bits / 8U], &_size_bytes3_);
        if (_err6_ < 0)
        {
            return _err6_;
        }
        // It is assumed that we know the exact type of the serialized entity, hence we expect the size to match.
        NUNAVUT_ASSERT((_size_bytes3_ * 8U) == 512ULL);
        offset_bits += _size_bytes3_ * 8U;  // Advance by the size of the nested object.
        NUNAVUT_ASSERT(offset_bits <= (capacity_bytes * 8U));
    }
    if (offset_bits % 8U != 0U)  // Pad to 8 bits. TODO: Eliminate redundant padding checks.
    {
        const uint8_t _pad3_ = (uint8_t)(8U - offset_bits % 8U);
        NUNAVUT_ASSERT(_pad3_ > 0);
        const int8_t _err7_ = nunavutSetUxx(&buffer[0], capacity_bytes, offset_bits, 0U, _pad3_);  // Optimize?
        if (_err7_ < 0)
        {
            return _err7_;
        }
        offset_bits += _pad3_;
        NUNAVUT_ASSERT(offset_bits % 8U == 0U);
    }
    // It is assumed that we know the exact type of the serialized entity, hence we expect the size to match.
    NUNAVUT_ASSERT(offset_bits >= 128ULL);
    NUNAVUT_ASSERT(offset_bits <= 67728ULL);
    NUNAVUT_ASSERT(offset_bits % 8U == 0U);
    *inout_buffer_size_bytes = (size_t) (offset_bits / 8U);
    return NUNAVUT_SUCCESS;
}

/// Deserialize an instance from the provided buffer.
/// The lifetime of the resulting object is independent of the original buffer.
/// This method may be slow for large objects (e.g., images, point clouds, radar samples), so in a later revision
/// we may define a zero-copy alternative that keeps references to the original buffer where possible.
///
/// @param obj      The object to update from the provided serialized representation.
///
/// @param buffer   The source buffer containing the serialized representation. There are no alignment requirements.
///                 If the buffer is shorter or longer than expected, it will be implicitly zero-extended or truncated,
///                 respectively; see Specification for "implicit zero extension" and "implicit truncation" rules.
///
/// @param inout_buffer_size_bytes  When calling, this is a pointer to the size of the supplied serialized
///                                 representation, in bytes. Upon return this value will be updated with the
///                                 size of the consumed fragment of the serialized representation (in bytes),
///                                 which may be smaller due to the implicit truncation rule, but it is guaranteed
///                                 to never exceed the original buffer size even if the implicit zero extension rule
///                                 was activated. In case of error this value is undefined.
///
/// @returns Negative on error, zero on success.
static inline int8_t uavcan_node_port_List_0_1_deserialize_(
    uavcan_node_port_List_0_1* const out_obj, const uint8_t* buffer, size_t* const inout_buffer_size_bytes)
{
    if ((out_obj == NULL) || (inout_buffer_size_bytes == NULL) || ((buffer == NULL) && (0 != *inout_buffer_size_bytes)))
    {
        return -NUNAVUT_ERROR_INVALID_ARGUMENT;
    }
    if (buffer == NULL)
    {
        buffer = (const uint8_t*)"";
    }
    const size_t capacity_bytes = *inout_buffer_size_bytes;
    const size_t capacity_bits = capacity_bytes * (size_t) 8U;
    size_t offset_bits = 0U;
    // uavcan.node.port.SubjectIDList.0.1 publishers
    NUNAVUT_ASSERT(offset_bits % 8U == 0U);
    NUNAVUT_ASSERT(offset_bits % 8U == 0U);
    {
        // Delimiter header: truncated uint32
        size_t _size_bytes4_ = 0U;
        _size_bytes4_ = nunavutGetU32(&buffer[0], capacity_bytes, offset_bits, 32);
        offset_bits += 32U;
        if (_size_bytes4_ > (capacity_bytes - nunavutChooseMin((offset_bits / 8U), capacity_bytes)))
        {
            return -NUNAVUT_ERROR_REPRESENTATION_BAD_DELIMITER_HEADER;
        }
        const size_t _dh0_ = _size_bytes4_;  // Store the original delimiter header value.
        NUNAVUT_ASSERT(offset_bits % 8U == 0U);
        const int8_t _err8_ = uavcan_node_port_SubjectIDList_0_1_deserialize_(
            &out_obj->publishers, &buffer[offset_bits / 8U], &_size_bytes4_);
        if (_err8_ < 0)
        {
            return _err8_;
        }
        // Advance the offset by the size of the delimiter header, even if the nested deserialization routine
        // consumed fewer bytes of data. This behavior implements the implicit truncation rule for nested objects.
        offset_bits += _dh0_ * 8U;
    }
    offset_bits = (offset_bits + 7U) & ~(size_t) 7U;  // Align on 8 bits.
    // uavcan.node.port.SubjectIDList.0.1 subscribers
    NUNAVUT_ASSERT(offset_bits % 8U == 0U);
    NUNAVUT_ASSERT(offset_bits % 8U == 0U);
    {
        // Delimiter header: truncated uint32
        size_t _size_bytes5_ = 0U;
        _size_bytes5_ = nunavutGetU32(&buffer[0], capacity_bytes, offset_bits, 32);
        offset_bits += 32U;
        if (_size_bytes5_ > (capacity_bytes - nunavutChooseMin((offset_bits / 8U), capacity_bytes)))
        {
            return -NUNAVUT_ERROR_REPRESENTATION_BAD_DELIMITER_HEADER;
        }
        const size_t _dh1_ = _size_bytes5_;  // Store the original delimiter header value.
        NUNAVUT_ASSERT(offset_bits % 8U == 0U);
        const int8_t _err9_ = uavcan_node_port_SubjectIDList_0_1_deserialize_(
            &out_obj->subscribers, &buffer[offset_bits / 8U], &_size_bytes5_);
        if (_err9_ < 0)
        {
            return _err9_;
        }
        // Advance the offset by the size of the delimiter header, even if the nested deserialization routine
        // consumed fewer bytes of data. This behavior implements the implicit truncation rule for nested objects.
        offset_bits += _dh1_ * 8U;
    }
    offset_bits = (offset_bits + 7U) & ~(size_t) 7U;  // Align on 8 bits.
    // uavcan.node.port.ServiceIDList.0.1 clients
    NUNAVUT_ASSERT(offset_bits % 8U == 0U);
    NUNAVUT_ASSERT(offset_bits % 8U == 0U);
    {
        // Delimiter header: truncated uint32
        size_t _size_bytes6_ = 0U;
        _size_bytes6_ = nunavutGetU32(&buffer[0], capacity_bytes, offset_bits, 32);
        offset_bits += 32U;
        if (_size_bytes6_ > (capacity_bytes - nunavutChooseMin((offset_bits / 8U), capacity_bytes)))
        {
            return -NUNAVUT_ERROR_REPRESENTATION_BAD_DELIMITER_HEADER;
        }
        const size_t _dh2_ = _size_bytes6_;  // Store the original delimiter header value.
        NUNAVUT_ASSERT(offset_bits % 8U == 0U);
        const int8_t _err10_ = uavcan_node_port_ServiceIDList_0_1_deserialize_(
            &out_obj->clients, &buffer[offset_bits / 8U], &_size_bytes6_);
        if (_err10_ < 0)
        {
            return _err10_;
        }
        // Advance the offset by the size of the delimiter header, even if the nested deserialization routine
        // consumed fewer bytes of data. This behavior implements the implicit truncation rule for nested objects.
        offset_bits += _dh2_ * 8U;
    }
    offset_bits = (offset_bits + 7U) & ~(size_t) 7U;  // Align on 8 bits.
    // uavcan.node.port.ServiceIDList.0.1 servers
    NUNAVUT_ASSERT(offset_bits % 8U == 0U);
    NUNAVUT_ASSERT(offset_bits % 8U == 0U);
    {
        // Delimiter header: truncated uint32
        size_t _size_bytes7_ = 0U;
        _size_bytes7_ = nunavutGetU32(&buffer[0], capacity_bytes, offset_bits, 32);
        offset_bits += 32U;
        if (_size_bytes7_ > (capacity_bytes - nunavutChooseMin((offset_bits / 8U), capacity_bytes)))
        {
            return -NUNAVUT_ERROR_REPRESENTATION_BAD_DELIMITER_HEADER;
        }
        const size_t _dh3_ = _size_bytes7_;  // Store the original delimiter header value.
        NUNAVUT_ASSERT(offset_bits % 8U == 0U);
        const int8_t _err11_ = uavcan_node_port_ServiceIDList_0_1_deserialize_(
            &out_obj->servers, &buffer[offset_bits / 8U], &_size_bytes7_);
        if (_err11_ < 0)
        {
            return _err11_;
        }
        // Advance the offset by the size of the delimiter header, even if the nested deserialization routine
        // consumed fewer bytes of data. This behavior implements the implicit truncation rule for nested objects.
        offset_bits += _dh3_ * 8U;
    }
    offset_bits = (offset_bits + 7U) & ~(size_t) 7U;  // Align on 8 bits.
    NUNAVUT_ASSERT(offset_bits % 8U == 0U);
    *inout_buffer_size_bytes = (size_t) (nunavutChooseMin(offset_bits, capacity_bits) / 8U);
    NUNAVUT_ASSERT(capacity_bytes >= *inout_buffer_size_bytes);
    return NUNAVUT_SUCCESS;
}

/// Initialize an instance to default values. Does nothing if @param out_obj is NULL.
/// This function intentionally leaves inactive elements uninitialized; for example, members of a variable-length
/// array beyond its length are left uninitialized; aliased union memory that is not used by the first union field
/// is left uninitialized, etc. If full zero-initialization is desired, just use memset(&obj, 0, sizeof(obj)).
static inline void uavcan_node_port_List_0_1_initialize_(uavcan_node_port_List_0_1* const out_obj)
{
    if (out_obj != NULL)
    {
        size_t size_bytes = 0;
        const uint8_t buf = 0;
        const int8_t err = uavcan_node_port_List_0_1_deserialize_(out_obj, &buf, &size_bytes);
        NUNAVUT_ASSERT(err >= 0);
        (void) err;
    }
}

#ifdef __cplusplus
}
#endif
#endif // UAVCAN_NODE_PORT_LIST_0_1_INCLUDED_
