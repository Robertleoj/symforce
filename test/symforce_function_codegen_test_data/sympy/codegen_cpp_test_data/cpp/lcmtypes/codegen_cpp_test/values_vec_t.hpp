/** THIS IS AN AUTOMATICALLY GENERATED FILE.  DO NOT MODIFY
 * BY HAND!!
 *
 * Generated by lcm-gen
 **/

#include <lcm/lcm_coretypes.h>
#include <lcm/lcm_cpptypes.hpp>

#ifndef __codegen_cpp_test_values_vec_t_hpp__
#define __codegen_cpp_test_values_vec_t_hpp__

#if defined(SKYMARSHAL_PRINTING_ENABLED)
#include <lcm/lcm_reflection.hpp>
#include <array>
#endif
#include <ostream>

#include <array>
#include "lcmtypes/eigen_lcm/Vector4d.hpp"

namespace codegen_cpp_test
{

class values_vec_t
{
    public:
        double x;

        double y;

        ::eigen_lcm::Vector4d rot;

        std::array< ::eigen_lcm::Vector4d, 3 > rot_vec;

        std::array< double, 3 > scalar_vec;

        std::array< std::array< ::eigen_lcm::Vector4d, 3 >, 3 > list_of_lists;

    public:
        values_vec_t() = default;

        /**
         * Member constructor
         */
        inline values_vec_t(
            const double& x_arg,
            const double& y_arg,
            const ::eigen_lcm::Vector4d& rot_arg,
            const std::array< ::eigen_lcm::Vector4d, 3 >& rot_vec_arg,
            const std::array< double, 3 >& scalar_vec_arg,
            const std::array< std::array< ::eigen_lcm::Vector4d, 3 >, 3 >& list_of_lists_arg
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
        inline static uint64_t getHash();

        using type_name_array_t = const char[13];

        inline static constexpr type_name_array_t* getTypeNameArrayPtr();

        /**
         * Returns "values_vec_t"
         */
        inline static constexpr const char* getTypeName();

        using package_name_array_t = const char[17];

        inline static constexpr package_name_array_t* getPackageNameArrayPtr();

        /**
         * Returns "codegen_cpp_test"
         */
        inline static constexpr const char * getPackageName();

        // LCM support functions. Users should not call these
        inline __lcm_buffer_size _encodeNoHash(void *buf, __lcm_buffer_size offset, __lcm_buffer_size maxlen) const;
        inline __lcm_buffer_size _getEncodedSizeNoHash() const;
        inline __lcm_buffer_size _decodeNoHash(const void *buf, __lcm_buffer_size offset, __lcm_buffer_size maxlen);
#if !defined(SKYDIO_DISABLE_LCM_NO_INLINE)
        __attribute__((noinline))
#endif
        static uint64_t _computeHash(const __lcm_hash_ptr *p)
        {
            const __lcm_hash_ptr *fp;
            for(fp = p; fp != NULL; fp = fp->parent)
                if(fp->v == values_vec_t::getHash)
                    return 0;
            const __lcm_hash_ptr cp = { p, values_vec_t::getHash };

            uint64_t hash = 0xe7b60b55c8cf5417LL +
                ::eigen_lcm::Vector4d::_computeHash(&cp) +
         ::eigen_lcm::Vector4d::_computeHash(&cp) +
         ::eigen_lcm::Vector4d::_computeHash(&cp);

            return (hash<<1) + ((hash>>63)&1);
        }

        // Comparison operators.
        inline bool operator==(const values_vec_t& other) const;
        inline bool operator!=(const values_vec_t& other) const;

#if defined(SKYMARSHAL_PRINTING_ENABLED)
        constexpr static std::array<const char*, 6> fields()
        {
            return {{
                "x",
                "y",
                "rot",
                "rot_vec",
                "scalar_vec",
                "list_of_lists",
            }};
        }

        // Given a string field path, translate the entire path to field / list indices within this struct.
        // Return value is 0 if the operation succeeded.
        // If the operation failed, return value is equal to 1 + the index of the first invalid field.
        static uint32_t translate_fields(const char* const _fields[], uint32_t _field_indices_out[], uint32_t _num_fields) {
            if (strcmp(_fields[0], fields()[0]) == 0) {
                _field_indices_out[0] = 0;
                uint32_t ret = lcm::translate_fields<decltype(values_vec_t::x)>(_fields + 1, _field_indices_out + 1, _num_fields - 1);
                return ret == 0 ? ret : ret + 1;
            }
            if (strcmp(_fields[0], fields()[1]) == 0) {
                _field_indices_out[0] = 1;
                uint32_t ret = lcm::translate_fields<decltype(values_vec_t::y)>(_fields + 1, _field_indices_out + 1, _num_fields - 1);
                return ret == 0 ? ret : ret + 1;
            }
            if (strcmp(_fields[0], fields()[2]) == 0) {
                _field_indices_out[0] = 2;
                uint32_t ret = lcm::translate_fields<decltype(values_vec_t::rot)>(_fields + 1, _field_indices_out + 1, _num_fields - 1);
                return ret == 0 ? ret : ret + 1;
            }
            if (strcmp(_fields[0], fields()[3]) == 0) {
                _field_indices_out[0] = 3;
                uint32_t ret = lcm::translate_fields<decltype(values_vec_t::rot_vec)>(_fields + 1, _field_indices_out + 1, _num_fields - 1);
                return ret == 0 ? ret : ret + 1;
            }
            if (strcmp(_fields[0], fields()[4]) == 0) {
                _field_indices_out[0] = 4;
                uint32_t ret = lcm::translate_fields<decltype(values_vec_t::scalar_vec)>(_fields + 1, _field_indices_out + 1, _num_fields - 1);
                return ret == 0 ? ret : ret + 1;
            }
            if (strcmp(_fields[0], fields()[5]) == 0) {
                _field_indices_out[0] = 5;
                uint32_t ret = lcm::translate_fields<decltype(values_vec_t::list_of_lists)>(_fields + 1, _field_indices_out + 1, _num_fields - 1);
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
                ret = lcm::show_field(_stream, _field_indices + 1, _num_fields - 1, x, _indent);
                return ret == 0 ? ret : ret + 1;
                case 1:
                ret = lcm::show_field(_stream, _field_indices + 1, _num_fields - 1, y, _indent);
                return ret == 0 ? ret : ret + 1;
                case 2:
                ret = lcm::show_field(_stream, _field_indices + 1, _num_fields - 1, rot, _indent);
                return ret == 0 ? ret : ret + 1;
                case 3:
                ret = lcm::show_field(_stream, _field_indices + 1, _num_fields - 1, rot_vec, _indent);
                return ret == 0 ? ret : ret + 1;
                case 4:
                ret = lcm::show_field(_stream, _field_indices + 1, _num_fields - 1, scalar_vec, _indent);
                return ret == 0 ? ret : ret + 1;
                case 5:
                ret = lcm::show_field(_stream, _field_indices + 1, _num_fields - 1, list_of_lists, _indent);
                return ret == 0 ? ret : ret + 1;
                default:
                return 1;
            }
        }

        // Ability to print to standard streams as well as the fmt library.
        friend std::ostream& operator<<(std::ostream& _stream, const values_vec_t& obj) {
            lcm::show_field(_stream, nullptr, 0, obj, 0);
            return _stream;
        }

#else
        friend std::ostream& operator<<(std::ostream& _stream, const values_vec_t& obj) {
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
                ret = lcm::store_field(_field_indices + 1, _num_fields - 1, x, _value);
                return ret == 0 ? ret : ret + 1;
                case 1:
                ret = lcm::store_field(_field_indices + 1, _num_fields - 1, y, _value);
                return ret == 0 ? ret : ret + 1;
                case 2:
                ret = lcm::store_field(_field_indices + 1, _num_fields - 1, rot, _value);
                return ret == 0 ? ret : ret + 1;
                case 3:
                ret = lcm::store_field(_field_indices + 1, _num_fields - 1, rot_vec, _value);
                return ret == 0 ? ret : ret + 1;
                case 4:
                ret = lcm::store_field(_field_indices + 1, _num_fields - 1, scalar_vec, _value);
                return ret == 0 ? ret : ret + 1;
                case 5:
                ret = lcm::store_field(_field_indices + 1, _num_fields - 1, list_of_lists, _value);
                return ret == 0 ? ret : ret + 1;
                default:
                return 1;
            }
        }
#endif
};

values_vec_t::values_vec_t(
    const double& x_arg,
    const double& y_arg,
    const ::eigen_lcm::Vector4d& rot_arg,
    const std::array< ::eigen_lcm::Vector4d, 3 >& rot_vec_arg,
    const std::array< double, 3 >& scalar_vec_arg,
    const std::array< std::array< ::eigen_lcm::Vector4d, 3 >, 3 >& list_of_lists_arg
) : x(x_arg),
    y(y_arg),
    rot(rot_arg),
    rot_vec(rot_vec_arg),
    scalar_vec(scalar_vec_arg),
    list_of_lists(list_of_lists_arg) {}

__lcm_buffer_size values_vec_t::encode(void *buf, __lcm_buffer_size offset, __lcm_buffer_size maxlen) const
{
    __lcm_buffer_size pos = 0, tlen;
    uint64_t hash = getHash();

    tlen = __uint64_t_encode_array(buf, offset + pos, maxlen - pos, &hash, 1);
    if(tlen < 0) return tlen; else pos += tlen;

    tlen = this->_encodeNoHash(buf, offset + pos, maxlen - pos);
    if (tlen < 0) return tlen; else pos += tlen;

    return pos;
}

__lcm_buffer_size values_vec_t::decode(const void *buf, __lcm_buffer_size offset, __lcm_buffer_size maxlen)
{
    __lcm_buffer_size pos = 0, thislen;

    uint64_t hash;
    thislen = __uint64_t_decode_array(buf, offset + pos, maxlen - pos, &hash, 1);
    if (thislen < 0) return thislen; else pos += thislen;
    if (hash != getHash()) return -1;

    thislen = this->_decodeNoHash(buf, offset + pos, maxlen - pos);
    if (thislen < 0) return thislen; else pos += thislen;

    return pos;
}

__lcm_buffer_size values_vec_t::getEncodedSize() const
{
    return 8 + _getEncodedSizeNoHash();
}

uint64_t values_vec_t::getHash()
{
    static uint64_t hash = _computeHash(NULL);
    return hash;
}

constexpr values_vec_t::type_name_array_t* values_vec_t::getTypeNameArrayPtr() {
    return &"values_vec_t";
}

constexpr const char* values_vec_t::getTypeName()
{
    return *values_vec_t::getTypeNameArrayPtr();
}

constexpr values_vec_t::package_name_array_t* values_vec_t::getPackageNameArrayPtr() {
    return &"codegen_cpp_test";
}

constexpr const char * values_vec_t::getPackageName()
{
    return *values_vec_t::getPackageNameArrayPtr();
}

__lcm_buffer_size values_vec_t::_encodeNoHash(void *buf, __lcm_buffer_size offset, __lcm_buffer_size maxlen) const
{
    __lcm_buffer_size pos = 0, tlen;

    tlen = __double_encode_array(buf, offset + pos, maxlen - pos, &this->x, 1);
    if(tlen < 0) return tlen; else pos += tlen;

    tlen = __double_encode_array(buf, offset + pos, maxlen - pos, &this->y, 1);
    if(tlen < 0) return tlen; else pos += tlen;

    tlen = this->rot._encodeNoHash(buf, offset + pos, maxlen - pos);
    if(tlen < 0) return tlen; else pos += tlen;

    for (__lcm_buffer_size a0 = 0; a0 < 3; a0++) {
        tlen = this->rot_vec[a0]._encodeNoHash(buf, offset + pos, maxlen - pos);
        if(tlen < 0) return tlen; else pos += tlen;
    }

    tlen = __double_encode_array(buf, offset + pos, maxlen - pos, &this->scalar_vec[0], 3);
    if(tlen < 0) return tlen; else pos += tlen;

    for (__lcm_buffer_size a0 = 0; a0 < 3; a0++) {
        for (__lcm_buffer_size a1 = 0; a1 < 3; a1++) {
            tlen = this->list_of_lists[a0][a1]._encodeNoHash(buf, offset + pos, maxlen - pos);
            if(tlen < 0) return tlen; else pos += tlen;
        }
    }

    return pos;
}

__lcm_buffer_size values_vec_t::_decodeNoHash(const void *buf, __lcm_buffer_size offset, __lcm_buffer_size maxlen)
{
    __lcm_buffer_size pos = 0, tlen;

    tlen = __double_decode_array(buf, offset + pos, maxlen - pos, &this->x, 1);
    if(tlen < 0) return tlen; else pos += tlen;

    tlen = __double_decode_array(buf, offset + pos, maxlen - pos, &this->y, 1);
    if(tlen < 0) return tlen; else pos += tlen;

    tlen = this->rot._decodeNoHash(buf, offset + pos, maxlen - pos);
    if(tlen < 0) return tlen; else pos += tlen;

    for (__lcm_buffer_size a0 = 0; a0 < 3; a0++) {
        tlen = this->rot_vec[a0]._decodeNoHash(buf, offset + pos, maxlen - pos);
        if(tlen < 0) return tlen; else pos += tlen;
    }

    tlen = __double_decode_array(buf, offset + pos, maxlen - pos, &this->scalar_vec[0], 3);
    if(tlen < 0) return tlen; else pos += tlen;

    for (__lcm_buffer_size a0 = 0; a0 < 3; a0++) {
        for (__lcm_buffer_size a1 = 0; a1 < 3; a1++) {
            tlen = this->list_of_lists[a0][a1]._decodeNoHash(buf, offset + pos, maxlen - pos);
            if(tlen < 0) return tlen; else pos += tlen;
        }
    }

    return pos;
}

__lcm_buffer_size values_vec_t::_getEncodedSizeNoHash() const
{
    __lcm_buffer_size enc_size = 0;
    enc_size += __double_encoded_array_size(NULL, 1);
    enc_size += __double_encoded_array_size(NULL, 1);
    enc_size += this->rot._getEncodedSizeNoHash();
    for (__lcm_buffer_size a0 = 0; a0 < 3; a0++) {
        enc_size += this->rot_vec[a0]._getEncodedSizeNoHash();
    }
    enc_size += __double_encoded_array_size(NULL, 3);
    for (__lcm_buffer_size a0 = 0; a0 < 3; a0++) {
        for (__lcm_buffer_size a1 = 0; a1 < 3; a1++) {
            enc_size += this->list_of_lists[a0][a1]._getEncodedSizeNoHash();
        }
    }
    return enc_size;
}

bool values_vec_t::operator==(const values_vec_t& other) const {
  return (
          (x==other.x) && 
          (y==other.y) && 
          (rot==other.rot) && 
          (rot_vec==other.rot_vec) && 
          (scalar_vec==other.scalar_vec) && 
          (list_of_lists==other.list_of_lists));
}

bool values_vec_t::operator!=(const values_vec_t& other) const {
  return !(*this==other);
}

}

#endif