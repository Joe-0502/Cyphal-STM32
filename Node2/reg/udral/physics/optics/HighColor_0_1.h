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
// Source file:   /tmp/pyuavcan-cli-dsdl6mzrytyr/public_regulated_data_types-master/reg/udral/physics/optics/HighColor.0.1.dsdl
// Generated at:  2025-04-15 13:30:18.166040 UTC
// Is deprecated: no
// Fixed port-ID: None
// Full name:     reg.udral.physics.optics.HighColor
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

#ifndef REG_UDRAL_PHYSICS_OPTICS_HIGH_COLOR_0_1_INCLUDED_
#define REG_UDRAL_PHYSICS_OPTICS_HIGH_COLOR_0_1_INCLUDED_

#include <nunavut/support/serialization.h>
#include <stdint.h>
#include <stdlib.h>

static_assert( NUNAVUT_SUPPORT_LANGUAGE_OPTION_TARGET_ENDIANNESS == 434322821,
              "/tmp/pyuavcan-cli-dsdl6mzrytyr/public_regulated_data_types-master/reg/udral/physics/optics/HighColor.0.1.dsdl is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not allowed." );
static_assert( NUNAVUT_SUPPORT_LANGUAGE_OPTION_OMIT_FLOAT_SERIALIZATION_SUPPORT == 0,
              "/tmp/pyuavcan-cli-dsdl6mzrytyr/public_regulated_data_types-master/reg/udral/physics/optics/HighColor.0.1.dsdl is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not allowed." );
static_assert( NUNAVUT_SUPPORT_LANGUAGE_OPTION_ENABLE_SERIALIZATION_ASSERTS == 1,
              "/tmp/pyuavcan-cli-dsdl6mzrytyr/public_regulated_data_types-master/reg/udral/physics/optics/HighColor.0.1.dsdl is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not allowed." );
static_assert( NUNAVUT_SUPPORT_LANGUAGE_OPTION_ENABLE_OVERRIDE_VARIABLE_ARRAY_CAPACITY == 0,
              "/tmp/pyuavcan-cli-dsdl6mzrytyr/public_regulated_data_types-master/reg/udral/physics/optics/HighColor.0.1.dsdl is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not allowed." );
static_assert( NUNAVUT_SUPPORT_LANGUAGE_OPTION_CAST_FORMAT == 2368206204,
              "/tmp/pyuavcan-cli-dsdl6mzrytyr/public_regulated_data_types-master/reg/udral/physics/optics/HighColor.0.1.dsdl is trying to use a serialization library that was compiled with "
              "different language options. This is dangerous and therefore not allowed." );

#ifdef __cplusplus
extern "C" {
#endif

/// This type does not have a fixed port-ID. See https://forum.opencyphal.org/t/choosing-message-and-service-ids/889
#define reg_udral_physics_optics_HighColor_0_1_HAS_FIXED_PORT_ID_ false

// +-------------------------------------------------------------------------------------------------------------------+
// | reg.udral.physics.optics.HighColor.0.1
// +-------------------------------------------------------------------------------------------------------------------+
#define reg_udral_physics_optics_HighColor_0_1_FULL_NAME_             "reg.udral.physics.optics.HighColor"
#define reg_udral_physics_optics_HighColor_0_1_FULL_NAME_AND_VERSION_ "reg.udral.physics.optics.HighColor.0.1"

/// Extent is the minimum amount of memory required to hold any serialized representation of any compatible
/// version of the data type; or, on other words, it is the the maximum possible size of received objects of this type.
/// The size is specified in bytes (rather than bits) because by definition, extent is an integer number of bytes long.
/// When allocating a deserialization (RX) buffer for this data type, it should be at least extent bytes large.
/// When allocating a serialization (TX) buffer, it is safe to use the size of the largest serialized representation
/// instead of the extent because it provides a tighter bound of the object size; it is safe because the concrete type
/// is always known during serialization (unlike deserialization). If not sure, use extent everywhere.
#define reg_udral_physics_optics_HighColor_0_1_EXTENT_BYTES_                    2UL
#define reg_udral_physics_optics_HighColor_0_1_SERIALIZATION_BUFFER_SIZE_BYTES_ 2UL
static_assert(reg_udral_physics_optics_HighColor_0_1_EXTENT_BYTES_ >= reg_udral_physics_optics_HighColor_0_1_SERIALIZATION_BUFFER_SIZE_BYTES_,
              "Internal constraint violation");

/// saturated uint5 MAX_RED = 31
#define reg_udral_physics_optics_HighColor_0_1_MAX_RED (31U)

/// saturated uint6 MAX_GREEN = 63
#define reg_udral_physics_optics_HighColor_0_1_MAX_GREEN (63U)

/// saturated uint5 MAX_BLUE = 31
#define reg_udral_physics_optics_HighColor_0_1_MAX_BLUE (31U)

typedef struct
{
    /// saturated uint5 red
    uint8_t red;

    /// saturated uint6 green
    uint8_t green;

    /// saturated uint5 blue
    uint8_t blue;
} reg_udral_physics_optics_HighColor_0_1;

/// Serialize an instance into the provided buffer.
/// The lifetime of the resulting serialized representation is independent of the original instance.
/// This method may be slow for large objects (e.g., images, point clouds, radar samples), so in a later revision
/// we may define a zero-copy alternative that keeps references to the original object where possible.
///
/// @param obj      The object to serialize.
///
/// @param buffer   The destination buffer. There are no alignment requirements.
///                 @see reg_udral_physics_optics_HighColor_0_1_SERIALIZATION_BUFFER_SIZE_BYTES_
///
/// @param inout_buffer_size_bytes  When calling, this is a pointer to the size of the buffer in bytes.
///                                 Upon return this value will be updated with the size of the constructed serialized
///                                 representation (in bytes); this value is then to be passed over to the transport
///                                 layer. In case of error this value is undefined.
///
/// @returns Negative on error, zero on success.
static inline int8_t reg_udral_physics_optics_HighColor_0_1_serialize_(
    const reg_udral_physics_optics_HighColor_0_1* const obj, uint8_t* const buffer,  size_t* const inout_buffer_size_bytes)
{
    if ((obj == NULL) || (buffer == NULL) || (inout_buffer_size_bytes == NULL))
    {
        return -NUNAVUT_ERROR_INVALID_ARGUMENT;
    }
    const size_t capacity_bytes = *inout_buffer_size_bytes;
    if ((8U * (size_t) capacity_bytes) < 16UL)
    {
        return -NUNAVUT_ERROR_SERIALIZATION_BUFFER_TOO_SMALL;
    }
    // Notice that fields that are not an integer number of bytes long may overrun the space allocated for them
    // in the serialization buffer up to the next byte boundary. This is by design and is guaranteed to be safe.
    size_t offset_bits = 0U;
    {   // saturated uint5 red
        NUNAVUT_ASSERT(offset_bits % 8U == 0U);
        NUNAVUT_ASSERT((offset_bits + 5ULL) <= (capacity_bytes * 8U));
        uint8_t _sat0_ = obj->red;
        if (_sat0_ > 31U)
        {
            _sat0_ = 31U;
        }
        buffer[offset_bits / 8U] = (uint8_t)(_sat0_);  // C std, 6.3.1.3 Signed and unsigned integers
        offset_bits += 5U;
    }
    {   // saturated uint6 green
        NUNAVUT_ASSERT((offset_bits + 6ULL) <= (capacity_bytes * 8U));
        uint8_t _sat1_ = obj->green;
        if (_sat1_ > 63U)
        {
            _sat1_ = 63U;
        }
        const int8_t _err0_ = nunavutSetUxx(&buffer[0], capacity_bytes, offset_bits, _sat1_, 6U);
        if (_err0_ < 0)
        {
            return _err0_;
        }
        offset_bits += 6U;
    }
    {   // saturated uint5 blue
        NUNAVUT_ASSERT((offset_bits + 5ULL) <= (capacity_bytes * 8U));
        uint8_t _sat2_ = obj->blue;
        if (_sat2_ > 31U)
        {
            _sat2_ = 31U;
        }
        const int8_t _err1_ = nunavutSetUxx(&buffer[0], capacity_bytes, offset_bits, _sat2_, 5U);
        if (_err1_ < 0)
        {
            return _err1_;
        }
        offset_bits += 5U;
    }
    if (offset_bits % 8U != 0U)  // Pad to 8 bits. TODO: Eliminate redundant padding checks.
    {
        const uint8_t _pad0_ = (uint8_t)(8U - offset_bits % 8U);
        NUNAVUT_ASSERT(_pad0_ > 0);
        const int8_t _err2_ = nunavutSetUxx(&buffer[0], capacity_bytes, offset_bits, 0U, _pad0_);  // Optimize?
        if (_err2_ < 0)
        {
            return _err2_;
        }
        offset_bits += _pad0_;
        NUNAVUT_ASSERT(offset_bits % 8U == 0U);
    }
    // It is assumed that we know the exact type of the serialized entity, hence we expect the size to match.
    NUNAVUT_ASSERT(offset_bits == 16ULL);
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
static inline int8_t reg_udral_physics_optics_HighColor_0_1_deserialize_(
    reg_udral_physics_optics_HighColor_0_1* const out_obj, const uint8_t* buffer, size_t* const inout_buffer_size_bytes)
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
    // saturated uint5 red
    NUNAVUT_ASSERT(offset_bits % 8U == 0U);
    if ((offset_bits + 5U) <= capacity_bits)
    {
        out_obj->red = buffer[offset_bits / 8U] & 31U;
    }
    else
    {
        out_obj->red = 0U;
    }
    offset_bits += 5U;
    // saturated uint6 green
    out_obj->green = nunavutGetU8(&buffer[0], capacity_bytes, offset_bits, 6);
    offset_bits += 6U;
    // saturated uint5 blue
    out_obj->blue = nunavutGetU8(&buffer[0], capacity_bytes, offset_bits, 5);
    offset_bits += 5U;
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
static inline void reg_udral_physics_optics_HighColor_0_1_initialize_(reg_udral_physics_optics_HighColor_0_1* const out_obj)
{
    if (out_obj != NULL)
    {
        size_t size_bytes = 0;
        const uint8_t buf = 0;
        const int8_t err = reg_udral_physics_optics_HighColor_0_1_deserialize_(out_obj, &buf, &size_bytes);
        NUNAVUT_ASSERT(err >= 0);
        (void) err;
    }
}

#ifdef __cplusplus
}
#endif
#endif // REG_UDRAL_PHYSICS_OPTICS_HIGH_COLOR_0_1_INCLUDED_
