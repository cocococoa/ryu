#include "ryu/ryu.h"

#include <gtest/gtest.h>

using namespace ryu;

TEST(Single, Uint32Conversion) {
  EXPECT_FLOAT_EQ(2.9988165487136453e-38f, Single(0x01234567u).Value());
  EXPECT_FLOAT_EQ(1.4e-45f, Single(0x00000001u).Value());
  EXPECT_FLOAT_EQ(3.4028234e38f, Single(0x7f7fffffu).Value());
}

TEST(Single, IsInfinite) {
  EXPECT_TRUE((+Single::Infinity()).IsInfinite());
  EXPECT_TRUE((-Single::Infinity()).IsInfinite());
  EXPECT_FALSE(Single::NaN().IsInfinite());
  EXPECT_FALSE(Single(+0.0f).IsInfinite());
  EXPECT_FALSE(Single(-0.0f).IsInfinite());
  EXPECT_FALSE(Single(+1.0f).IsInfinite());
  EXPECT_FALSE(Single(-1.0f).IsInfinite());
}

TEST(Single, IsNan) {
  EXPECT_TRUE(Single::NaN().IsNan());
  EXPECT_TRUE(Single(0xFFFFF001u).IsNan());
  EXPECT_FALSE((+Single::Infinity()).IsNan());
  EXPECT_FALSE((-Single::Infinity()).IsNan());
  EXPECT_FALSE(Single(+0.0f).IsNan());
  EXPECT_FALSE(Single(-0.0f).IsNan());
  EXPECT_FALSE(Single(+1.0f).IsNan());
  EXPECT_FALSE(Single(-1.0f).IsNan());
}

TEST(Single, IsZero) {
  EXPECT_TRUE(Single(+0.0f).IsZero());
  EXPECT_TRUE(Single(-0.0f).IsZero());
  EXPECT_FALSE((+Single::Infinity()).IsZero());
  EXPECT_FALSE((-Single::Infinity()).IsZero());
  EXPECT_FALSE(Single::NaN().IsZero());
  EXPECT_FALSE(Single(+1.0f).IsZero());
  EXPECT_FALSE(Single(-1.0f).IsZero());
}

TEST(Single, Sign) {
  EXPECT_EQ(0, Single(+1.0f).Sign());
  EXPECT_EQ(1, Single(-1.0f).Sign());
  EXPECT_EQ(0, Single(+0.0f).Sign());
  EXPECT_EQ(1, Single(-0.0f).Sign());
  EXPECT_EQ(0, (+Single::Infinity()).Sign());
  EXPECT_EQ(1, (-Single::Infinity()).Sign());
}

TEST(Single, Exponent) {
  EXPECT_EQ(127, Single(+1.0f).Exponent());
  EXPECT_EQ(127, Single(-1.0f).Exponent());
  EXPECT_EQ(0, Single(+0.0f).Exponent());
  EXPECT_EQ(0, Single(-0.0f).Exponent());
  EXPECT_EQ(128, Single(+3.14f).Exponent());
  EXPECT_EQ(128, Single(-3.14f).Exponent());
}

TEST(Single, Mantissa) {
  EXPECT_EQ(0, Single(+1.0f).Mantissa());
  EXPECT_EQ(0, Single(-1.0f).Mantissa());
  EXPECT_EQ(0, Single(+0.0f).Mantissa());
  EXPECT_EQ(0, Single(-0.0f).Mantissa());
  EXPECT_EQ(4781507, Single(+3.14f).Mantissa());
  EXPECT_EQ(4781507, Single(-3.14f).Mantissa());
}
