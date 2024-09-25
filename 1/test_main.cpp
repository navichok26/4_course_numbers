#include <gtest/gtest.h>
#include "algos.hpp"

// Тест для функции add
TEST(AddTest, PositiveNumbers) {
    EXPECT_EQ(add(3, 4), 7);
    EXPECT_EQ(add(1, 1), 2);
}

TEST(AddTest, NegativeNumbers) {
    EXPECT_EQ(add(-3, -4), -7);
    EXPECT_EQ(add(-1, -1), -2);
}

TEST(AddTest, MixedNumbers) {
    EXPECT_EQ(add(3, -4), -1);
    EXPECT_EQ(add(-1, 1), 0);
}