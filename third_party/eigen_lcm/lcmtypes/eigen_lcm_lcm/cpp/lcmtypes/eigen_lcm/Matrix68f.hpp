// This file was hand-written, modified from the Matrix68f type, with the hash
// generated by skymarshal.
#pragma once
#include <utility>

#include <lcm/lcm_coretypes.h>
#ifdef SKYMARSHAL_PRINTING_ENABLED
#include <lcm/lcm_reflection_eigen.hpp>
#endif
#include <Eigen/Core>

namespace eigen_lcm {

class Matrix68f : public Eigen::Matrix<float, 6, 8, Eigen::DontAlign> {
 public:
  // Default constructor. Unlike Eigen, eigen_lcm types initialize themselves to zero.
  // This is to prevent all sorts of uninitialized memory footguns.
  // Since the X sized variants are zero-sized by default, it is OK to default construct them.
  Matrix68f() : Eigen::Matrix<float, 6, 8, Eigen::DontAlign>() {
    *this = Matrix68f::Zero();
  }

  // Pass through constructor
  template <typename... Args>
  Matrix68f(Args&&... args) : Eigen::Matrix<float, 6, 8, Eigen::DontAlign>(args...) {}

  // This method allows you to assign Eigen expressions to eigen_lcm::Matrix68f
  template <typename OtherDerived>
  eigen_lcm::Matrix68f& operator=(const Eigen::MatrixBase<OtherDerived>& other) {
    Eigen::Matrix<float, 6, 8, Eigen::DontAlign>::operator=(other);
    return *this;
  }

  // Stream formatting operator
  friend std::ostream& operator<<(std::ostream& os, const eigen_lcm::Matrix68f& obj) {
    os << "Matrix68f(";
    for (size_t i = 0; i < obj.size(); ++i) {
      os << obj.data()[i];
      if (i + 1 != obj.size()) {
        os << ", ";
      }
    }
    os << ")";
    return os;
  }

 private:
  // Disable comma initialization magic for eigen_lcm types
  template <typename T>
  Eigen::Matrix<float, 6, 8, Eigen::DontAlign>& operator<<(T other);

 public:
  /**
   * Encode a message into binary form.
   *
   * @param buf The output buffer.
   * @param offset Encoding starts at thie byte offset into @p buf.
   * @param maxlen Maximum number of bytes to write.  This should generally be
   *  equal to getEncodedSize().
   * @return The number of bytes encoded, or <0 on error.
   */
  inline __lcm_buffer_size encode(void* buf, __lcm_buffer_size offset,
                                  __lcm_buffer_size maxlen) const;

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
  inline __lcm_buffer_size decode(const void* buf, __lcm_buffer_size offset,
                                  __lcm_buffer_size maxlen);

  /**
   * Retrieve the 64-bit fingerprint identifying the structure of the message.
   * Note that the fingerprint is the same for all instances of the same
   * message type, and is a fingerprint on the message type definition, not on
   * the message contents.
   */
  constexpr static uint64_t getHash();

  using type_name_array_t = const char[10];

  inline static constexpr type_name_array_t* getTypeNameArrayPtr();

  /**
   * Returns "Matrix68f"
   */
  inline static constexpr const char* getTypeName();

  using package_name_array_t = const char[10];

  inline static constexpr package_name_array_t* getPackageNameArrayPtr();

  /**
   * Returns "eigen_lcm"
   */
  inline static constexpr const char* getPackageName();

  // LCM support functions. Users should not call these
  inline __lcm_buffer_size _encodeNoHash(void* buf, __lcm_buffer_size offset,
                                         __lcm_buffer_size maxlen) const;
  inline __lcm_buffer_size _getEncodedSizeNoHash() const;
  inline __lcm_buffer_size _decodeNoHash(const void* buf, __lcm_buffer_size offset,
                                         __lcm_buffer_size maxlen);
  constexpr static uint64_t _computeHash(const __lcm_hash_ptr*) {
    uint64_t hash = 0x782a36eaf5255af0LL;
    return (hash << 1) + ((hash >> 63) & 1);
  }
};

__lcm_buffer_size Matrix68f::encode(void* buf, __lcm_buffer_size offset,
                                    __lcm_buffer_size maxlen) const {
  __lcm_buffer_size pos = 0, tlen;
  uint64_t hash = getHash();

  tlen = __uint64_t_encode_array(buf, offset + pos, maxlen - pos, &hash, 1);
  if (tlen < 0)
    return tlen;
  else
    pos += tlen;

  tlen = this->_encodeNoHash(buf, offset + pos, maxlen - pos);
  if (tlen < 0)
    return tlen;
  else
    pos += tlen;

  return pos;
}

__lcm_buffer_size Matrix68f::decode(const void* buf, __lcm_buffer_size offset,
                                    __lcm_buffer_size maxlen) {
  __lcm_buffer_size pos = 0, thislen;

  uint64_t hash;
  thislen = __uint64_t_decode_array(buf, offset + pos, maxlen - pos, &hash, 1);
  if (thislen < 0)
    return thislen;
  else
    pos += thislen;
  if (hash != getHash())
    return -1;

  thislen = this->_decodeNoHash(buf, offset + pos, maxlen - pos);
  if (thislen < 0)
    return thislen;
  else
    pos += thislen;

  return pos;
}

__lcm_buffer_size Matrix68f::getEncodedSize() const {
  return 8 + _getEncodedSizeNoHash();
}

constexpr uint64_t Matrix68f::getHash() {
  return _computeHash(NULL);
}

constexpr Matrix68f::type_name_array_t* Matrix68f::getTypeNameArrayPtr() {
  return &"Matrix68f";
}

constexpr const char* Matrix68f::getTypeName() {
  return *Matrix68f::getTypeNameArrayPtr();
}

constexpr Matrix68f::package_name_array_t* Matrix68f::getPackageNameArrayPtr() {
  return &"eigen_lcm";
}

constexpr const char* Matrix68f::getPackageName() {
  return *Matrix68f::getPackageNameArrayPtr();
}

__lcm_buffer_size Matrix68f::_encodeNoHash(void* buf, __lcm_buffer_size offset,
                                           __lcm_buffer_size maxlen) const {
  __lcm_buffer_size pos = 0, tlen;

  tlen = __float_encode_array(buf, offset + pos, maxlen - pos, this->data(), 48);
  if (tlen < 0)
    return tlen;
  else
    pos += tlen;

  return pos;
}

__lcm_buffer_size Matrix68f::_decodeNoHash(const void* buf, __lcm_buffer_size offset,
                                           __lcm_buffer_size maxlen) {
  __lcm_buffer_size pos = 0, tlen;

  tlen = __float_decode_array(buf, offset + pos, maxlen - pos, this->data(), 48);
  if (tlen < 0)
    return tlen;
  else
    pos += tlen;

  return pos;
}

__lcm_buffer_size Matrix68f::_getEncodedSizeNoHash() const {
  __lcm_buffer_size enc_size = 0;
  enc_size += __float_encoded_array_size(NULL, 48);
  return enc_size;
}

}  // namespace eigen_lcm
