#include <expected>

#include <gtest/gtest.h>

#include "algos.hpp"

TEST(BigNum, mod_sub_small)
{
    BN a, b;
    a = 2;
    b = 5;
    int n = 7;
    auto res = a.mod_sub(b, n);
    BN expect;
    expect = 4;
    EXPECT_TRUE(res == expect);
}

TEST(BigNum, mod_sub_big)
{
    BN a, b;
    a = 2;
    b = 22;
    int n = 7;
    auto res = a.mod_sub(b, n);
    BN expect;
    expect = 1;
    EXPECT_TRUE(res == expect);
}

TEST(BigNum, mod_inverse_simple)
{
    BN a, m;
    a = 17;
    m = 3120;
    BN inv = a.mod_inverse(m);
    BN expect;
    expect = 2753;  // 17 * 2753 % 3120 == 1

    EXPECT_TRUE(inv == expect);

    // Дополнительная проверка
    BN check = (a * inv) % m;
    EXPECT_TRUE(check == BN(1));
}

// 1.1
TEST(PollardAlgorithmTests, 1_1)
{
    BN g, a;
    g = 22;
    a = 418;
    int p = 599;
    auto res = pollard_pmethod(g, p, a);
    ASSERT_TRUE(res.has_value());
    EXPECT_EQ(*res, 185);
}

// 1.2
TEST(PollardAlgorithmTests, 1_2)
{
    BN g, a;
    g = 22;
    a = 183;
    int p = 599;
    auto res = pollard_pmethod(g, p, a);
    ASSERT_TRUE(res.has_value());
    EXPECT_EQ(*res, 321);
}

// 2.1
TEST(PollardAlgorithmTests, 2_1)
{
    BN g, a;
    g = 70;
    a = 21;
    int p = 599;
    auto res = pollard_pmethod(g, p, a);
    ASSERT_TRUE(res.has_value());
    EXPECT_EQ(*res, 221);
}

// 2.2
TEST(PollardAlgorithmTests, 2_2)
{
    BN g, a;
    g = 70;
    a = 269;
    int p = 599;
    auto res = pollard_pmethod(g, p, a);
    ASSERT_TRUE(res.has_value());
    EXPECT_EQ(*res, 436);
}

// 3.1
TEST(PollardAlgorithmTests, 3_1)
{
    BN g, a;
    g = 52;
    a = 647;
    int p = 1571;
    auto res = pollard_pmethod(g, p, a);
    ASSERT_TRUE(res.has_value());
    EXPECT_EQ(*res, 368);
}

// 3.2
TEST(PollardAlgorithmTests, 3_2)
{
    BN g, a;
    g = 52;
    a = 190;
    int p = 1571;
    auto res = pollard_pmethod(g, p, a);
    ASSERT_TRUE(res.has_value());
    EXPECT_EQ(*res, 1023);
}

// 4.1
TEST(PollardAlgorithmTests, 4_1)
{
    BN g, a;
    g = 1003;
    a = 912;
    int p = 1571;
    auto res = pollard_pmethod(g, p, a);
    ASSERT_TRUE(res.has_value());
    EXPECT_EQ(*res, 146);
}

// 4.2
TEST(PollardAlgorithmTests, 4_2)
{
    BN g, a;
    g = 1003;
    a = 25;
    int p = 1571;
    auto res = pollard_pmethod(g, p, a);
    ASSERT_TRUE(res.has_value());
    EXPECT_EQ(*res, 86);
}

// 5.1
TEST(PollardAlgorithmTests, 5_1)
{
    BN g, a;
    g = 77;
    a = 625;
    int p = 10069;
    auto res = pollard_pmethod(g, p, a);
    ASSERT_TRUE(res.has_value());
    EXPECT_EQ(*res, 156);
}

// 5.2
TEST(PollardAlgorithmTests, 5_2)
{
    BN g, a;
    g = 77;
    a = 7128;
    int p = 10069;
    auto res = pollard_pmethod(g, p, a);
    ASSERT_TRUE(res.has_value());
    EXPECT_EQ(*res, 835);
}

// 6.1
TEST(PollardAlgorithmTests, 6_1)
{
    BN g, a;
    g = 8900;
    a = 9458;
    int p = 10069;
    auto res = pollard_pmethod(g, p, a);
    ASSERT_TRUE(res.has_value());
    EXPECT_EQ(*res, 1024);
}

// 6.2
TEST(PollardAlgorithmTests, 6_2)
{
    BN g, a;
    g = 8900;
    a = 7330;
    int p = 10069;
    auto res = pollard_pmethod(g, p, a);
    ASSERT_TRUE(res.has_value());
    EXPECT_EQ(*res, 2356);
}