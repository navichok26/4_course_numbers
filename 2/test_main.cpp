#include <gtest/gtest.h>
#include "algos.hpp"

TEST(AlwayMethTest, Squares) {
    BN tmp = 121;
    auto res = factorize(tmp);
    EXPECT_TRUE(res);
    EXPECT_TRUE(res.value() == BN(11));
    tmp = 169;
    res = factorize(tmp);
    EXPECT_TRUE(res);
    EXPECT_TRUE(res.value() == BN(13));
}