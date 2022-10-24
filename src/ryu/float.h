#pragma once

#include <string>

namespace ryu {
class Float {};

class Single : public Float {
 public:
  static const std::uint32_t SignMask = 0b10000000000000000000000000000000;
  static const std::uint32_t ExponentMask = 0b01111111100000000000000000000000;
  static const std::uint32_t MantissaMask = 0b00000000011111111111111111111111;
  static const std::int32_t ExponentBits = 8;
  static const std::int32_t MantissaBits = 23;
  static const std::int32_t ExponentBias = 127;

  Single();
  Single(float x);
  Single(std::uint32_t x);
  static Single Infinity();
  static Single NaN();

  float Value() const;

  bool IsInfinite() const;
  bool IsNan() const;
  bool IsZero() const;

  std::int32_t Sign() const;
  std::int32_t Exponent() const;
  std::int32_t Mantissa() const;

  Single operator+() const;
  Single operator-() const;

 private:
  static const std::uint32_t Infinity_ = 0x7F800000;
  static const std::uint32_t NaN_ = 0x7FC00000;

  std::uint32_t d32_;
};
}  // namespace ryu
