#pragma once

#include <cstdint>

namespace ryu {
template <typename U, typename V>
V maskAndShift(const U x, const U mask, const std::int32_t shift) {
  return static_cast<V>((x & mask) >> shift);
}
inline std::uint32_t floatAsUint32(const float x) {
  return *reinterpret_cast<const std::uint32_t*>(&x);
}
inline float uint32AsFloat(const std::uint32_t x) {
  return *reinterpret_cast<const float*>(&x);
}
}  // namespace ryu
