#include <gtest/gtest.h>
#include "algos.hpp"


// 1.1
TEST(GelfondsAlgorithmTests, 1_1) {
    BN g, a;
    g = 22;
    a = 418;
    int p = 599;
    auto res = Gelfonds_algorithm(g, p, a);
    EXPECT_TRUE(res == 185);
}

// 1.2
TEST(GelfondsAlgorithmTests, 1_2) {
    BN g, a;
    g = 22;
    a = 183;
    int p = 599;
    auto res = Gelfonds_algorithm(g, p, a);
    EXPECT_TRUE(res == 321);
}

// 2.1
TEST(GelfondsAlgorithmTests, 2_1) {
    BN g, a;
    g = 70;
    a = 21;
    int p = 599;
    auto res = Gelfonds_algorithm(g, p, a);
    EXPECT_TRUE(res == 221);
}

// 2.2
TEST(GelfondsAlgorithmTests, 2_2) {
    BN g, a;
    g = 70;
    a = 269;
    int p = 599;
    auto res = Gelfonds_algorithm(g, p, a);
    EXPECT_TRUE(res == 436);
}

// 3.1
TEST(GelfondsAlgorithmTests, 3_1) {
    BN g, a;
    g = 52;
    a = 647;
    int p = 1571;
    auto res = Gelfonds_algorithm(g, p, a);
    EXPECT_TRUE(res == 368);
}

// 3.2
TEST(GelfondsAlgorithmTests, 3_2) {
    BN g, a;
    g = 52;
    a = 190;
    int p = 1571;
    auto res = Gelfonds_algorithm(g, p, a);
    EXPECT_TRUE(res == 1023);
}

// 4.1
TEST(GelfondsAlgorithmTests, 4_1) {
    BN g, a;
    g = 1003;
    a = 912;
    int p = 1571;
    auto res = Gelfonds_algorithm(g, p, a);
    EXPECT_TRUE(res == 146);
}

// 4.2
TEST(GelfondsAlgorithmTests, 4_2) {
    BN g, a;
    g = 1003;
    a = 25;
    int p = 1571;
    auto res = Gelfonds_algorithm(g, p, a);
    EXPECT_TRUE(res == 86);
}

// 5.1
TEST(GelfondsAlgorithmTests, 5_1) {
    BN g, a;
    g = 77;
    a = 625;
    int p = 10069;
    auto res = Gelfonds_algorithm(g, p, a);
    EXPECT_TRUE(res == 156);
}

// 5.2
TEST(GelfondsAlgorithmTests, 5_2) {
    BN g, a;
    g = 77;
    a = 7128;
    int p = 10069;
    auto res = Gelfonds_algorithm(g, p, a);
    EXPECT_TRUE(res == 835);
}

// 6.1
TEST(GelfondsAlgorithmTests, 6_1) {
    BN g, a;
    g = 8900;
    a = 9458;
    int p = 10069;
    auto res = Gelfonds_algorithm(g, p, a);
    EXPECT_TRUE(res == 1024);
}

// 6.2
TEST(GelfondsAlgorithmTests, 6_2) {
    BN g, a;
    g = 8900;
    a = 7330;
    int p = 10069;
    auto res = Gelfonds_algorithm(g, p, a);
    EXPECT_TRUE(res == 2356);
}