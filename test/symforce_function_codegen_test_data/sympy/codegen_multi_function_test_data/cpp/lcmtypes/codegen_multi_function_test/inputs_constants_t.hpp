/** THIS IS AN AUTOMATICALLY GENERATED FILE.  DO NOT MODIFY
 * BY HAND!!
 *
 * Generated by lcm-gen
 **/

#include <lcm/lcm_coretypes.h>
#include <lcm/lcm_cpptypes.hpp>

#ifndef __codegen_multi_function_test_inputs_constants_t_hpp__
#define __codegen_multi_function_test_inputs_constants_t_hpp__

#if defined(SKYMARSHAL_PRINTING_ENABLED)
#include <lcm/lcm_reflection.hpp>
#include <array>
#endif
#include <ostream>


namespace codegen_multi_function_test
{

class inputs_constants_t
{
    public:
        double epsilon;

    public:
        inputs_constants_t() = default;

        /**
         * Member constructor
         */
        inline inputs_constants_t(
            const double& epsilon_arg
        );

        /**
         * Encode a message into binary form.
         *
         * @param buf The output buffer.
         * @param offset Encoding starts at thie byte offset into @p buf.
         * @param maxlen Maximum number of bytes to write.  This should generally be
         *  equal to getEncodedSize().
         * @return The number of bytes encoded, or <0 on error.
         */
        inline __lcm_buffer_size encode(void *buf, __lcm_buffer_size offset, __lcm_buffer_size maxlen) const;

        /**
         * Check how many bytes are required to encode this message.
         */
        inline __lcm_buffer_size getEncodedSize() const;

        /**
         * Decode a message from binary form into this instance.
         *
         * @param buf The buffer containing the encoded message.
         * @param offset The byte offset into @p buf where the encoded message starts.
         * @param maxlen The maximum number of bytes to read while decoding.
         * @return The number of bytes decoded, or <0 if an error occured.
         */
        inline __lcm_buffer_size decode(const void *buf, __lcm_buffer_size offset, __lcm_buffer_size maxlen);

        /**
         * Retrieve the 64-bit fingerprint identifying the structure of the message.
         * Note that the fingerprint is the same for all instances of the same
         * message type, and is a fingerprint on the message type definition, not on
         * the message contents.
         */
        constexpr static int64_t getHash();

        using type_name_array_t = const char[19];

        inline static constexpr type_name_array_t* getTypeNameArrayPtr();

        /**
         * Returns "inputs_constants_t"
         */
        inline static constexpr const char* getTypeName();

        /**
         * Returns "codegen_multi_function_test"
         */
        inline static constexpr const char * getPackageName();

        // LCM support functions. Users should not call these
        inline __lcm_buffer_size _encodeNoHash(void *buf, __lcm_buffer_size offset, __lcm_buffer_size maxlen) const;
        inline __lcm_buffer_size _getEncodedSizeNoHash() const;
        inline __lcm_buffer_size _decodeNoHash(const void *buf, __lcm_buffer_size offset, __lcm_buffer_size maxlen);
        constexpr static uint64_t _computeHash(const __lcm_hash_ptr *)
        {
            uint64_t hash = 0x152f505c823f2cbcLL;
            return (hash<<1) + ((hash>>63)&1);
        }

        // Comparison operators.
        inline bool operator==(const inputs_constants_t& other) const;
        inline bool operator!=(const inputs_constants_t& other) const;

#if defined(SKYMARSHAL_PRINTING_ENABLED)
        constexpr static std::array<const char*, 1> fields()
        {
            return {{
                "epsilon",
            }};
        }

        // Given a string field path, translate the entire path to field / list indices within this struct.
        // Return value is 0 if the operation succeeded.
        // If the operation failed, return value is equal to 1 + the index of the first invalid field.
        static uint32_t translate_fields(const char* const _fields[], uint32_t _field_indices_out[], uint32_t _num_fields) {
            if (strcmp(_fields[0], fields()[0]) == 0) {
                _field_indices_out[0] = 0;
                uint32_t ret = lcm::translate_fields<decltype(inputs_constants_t::epsilon)>(_fields + 1, _field_indices_out + 1, _num_fields - 1);
                return ret == 0 ? ret : ret + 1;
            }
            return 1;

        }

        // Return value is 0 if the operation succeeded.
        // If the operation failed, return value is equal to 1 + the index of the first invalid field.
        uint32_t show_field(std::ostream& _stream, const uint32_t _field_indices[], uint32_t _num_fields, uint32_t _indent) const
        {
            uint32_t ret;
            switch (_field_indices[0]) {
                case 0:
                ret = lcm::show_field(_stream, _field_indices + 1, _num_fields - 1, epsilon, _indent);
                return ret == 0 ? ret : ret + 1;
                default:
                return 1;
            }
        }

        // Ability to print to standard streams as well as the fmt library.
        friend std::ostream& operator<<(std::ostream& _stream, const inputs_constants_t& obj) {
            lcm::show_field(_stream, nullptr, 0, obj, 0);
            return _stream;
        }

#else
        friend std::ostream& operator<<(std::ostream& _stream, const inputs_constants_t& obj) {
            _stream << "<FORMATTING DISABLED>";
            return _stream;
        }
#endif

#if defined(SKYMARSHAL_STORING_ENABLED)
        // Return value is 0 if the operation succeeded.
        // If the operation failed, return value is equal to 1 + the index of the first invalid field,
        // 1 + field_size if there are not enough fields, or 2 + field_size if the value is invalid.
        __attribute__((nodiscard)) uint32_t store_field(const uint32_t _field_indices[], uint32_t _num_fields, const char* const _value)
        {
            uint32_t ret;
            switch (_field_indices[0]) {
                case 0:
                ret = lcm::store_field(_field_indices + 1, _num_fields - 1, epsilon, _value);
                return ret == 0 ? ret : ret + 1;
                default:
                return 1;
            }
        }
#endif
};

inputs_constants_t::inputs_constants_t(
    const double& epsilon_arg
) : epsilon(epsilon_arg) {}

__lcm_buffer_size inputs_constants_t::encode(void *buf, __lcm_buffer_size offset, __lcm_buffer_size maxlen) const
{
    __lcm_buffer_size pos = 0, tlen;
    int64_t hash = (int64_t)getHash();

    tlen = __int64_t_encode_array(buf, offset + pos, maxlen - pos, &hash, 1);
    if(tlen < 0) return tlen; else pos += tlen;

    tlen = this->_encodeNoHash(buf, offset + pos, maxlen - pos);
    if (tlen < 0) return tlen; else pos += tlen;

    return pos;
}

__lcm_buffer_size inputs_constants_t::decode(const void *buf, __lcm_buffer_size offset, __lcm_buffer_size maxlen)
{
    __lcm_buffer_size pos = 0, thislen;

    int64_t msg_hash;
    thislen = __int64_t_decode_array(buf, offset + pos, maxlen - pos, &msg_hash, 1);
    if (thislen < 0) return thislen; else pos += thislen;
    if (msg_hash != getHash()) return -1;

    thislen = this->_decodeNoHash(buf, offset + pos, maxlen - pos);
    if (thislen < 0) return thislen; else pos += thislen;

    return pos;
}

__lcm_buffer_size inputs_constants_t::getEncodedSize() const
{
    return 8 + _getEncodedSizeNoHash();
}

constexpr int64_t inputs_constants_t::getHash()
{
    return static_cast<int64_t>(_computeHash(NULL));
}

constexpr inputs_constants_t::type_name_array_t* inputs_constants_t::getTypeNameArrayPtr() {
    return &"inputs_constants_t";
}

constexpr const char* inputs_constants_t::getTypeName()
{
    return *inputs_constants_t::getTypeNameArrayPtr();
}

constexpr const char * inputs_constants_t::getPackageName()
{
    return "codegen_multi_function_test";
}

__lcm_buffer_size inputs_constants_t::_encodeNoHash(void *buf, __lcm_buffer_size offset, __lcm_buffer_size maxlen) const
{
    __lcm_buffer_size pos = 0, tlen;

    tlen = __double_encode_array(buf, offset + pos, maxlen - pos, &this->epsilon, 1);
    if(tlen < 0) return tlen; else pos += tlen;

    return pos;
}

__lcm_buffer_size inputs_constants_t::_decodeNoHash(const void *buf, __lcm_buffer_size offset, __lcm_buffer_size maxlen)
{
    __lcm_buffer_size pos = 0, tlen;

    tlen = __double_decode_array(buf, offset + pos, maxlen - pos, &this->epsilon, 1);
    if(tlen < 0) return tlen; else pos += tlen;

    return pos;
}

__lcm_buffer_size inputs_constants_t::_getEncodedSizeNoHash() const
{
    __lcm_buffer_size enc_size = 0;
    enc_size += __double_encoded_array_size(NULL, 1);
    return enc_size;
}

bool inputs_constants_t::operator==(const inputs_constants_t& other) const {
  return (
          (epsilon==other.epsilon));
}

bool inputs_constants_t::operator!=(const inputs_constants_t& other) const {
  return !(*this==other);
}

}

#endif