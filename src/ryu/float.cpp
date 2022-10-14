#include "ryu/float.h"

namespace ryu {
Single::Single(const float x)
    : d32_(*reinterpret_cast<const std::uint32_t*>(&x)) {}
Single::Single(const std::uint32_t x) : d32_(x) {}
Single Single::Infinity() { return Single(Infinity_); }
Single Single::NaN() { return Single(NaN_); }

float Single::Value() const { return *reinterpret_cast<const float*>(&d32_); }

bool Single::IsInfinite() const {
  return (d32_ & ExponentMask) == ExponentMask && Mantissa() == 0;
}
bool Single::IsNan() const {
  return (d32_ & ExponentMask) == ExponentMask && Mantissa() != 0;
}

std::int32_t Single::Sign() const {
  return maskAndShift<std::uint32_t, std::int32_t>(d32_, SignMask,
                                                   ExponentBits + MantissaBits);
}
std::int32_t Single::Exponent() const {
  return maskAndShift<std::uint32_t, std::int32_t>(d32_, ExponentMask,
                                                   MantissaBits);
}
std::int32_t Single::Mantissa() const {
  return maskAndShift<std::uint32_t, std::int32_t>(d32_, MantissaMask, 0);
}

Single Single::operator+() const { return *this; }
Single Single::operator-() const { return Single(d32_ ^ SignMask); }
}  // namespace ryu
