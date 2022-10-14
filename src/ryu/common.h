#pragma once

#include <cstdint>

namespace ryu {
template <typename U, typename V>
V maskAndShift(const U x, const U mask, const std::int32_t shift) {
  return static_cast<V>((x & mask) >> shift);
}
}  // namespace ryu
