#include <vector>

#include <gtest/gtest.h>

#include "algos.hpp"
#include "polinom.hpp"

TEST(IrreducibleTest1, true_1)
{
    int p = 2;
    std::vector<int> coeffs_irred = {1, 0, 1, 1, 1, 0, 0, 0, 1};
    Polynomial f_irred(coeffs_irred, p);
    EXPECT_TRUE(is_primitive(f_irred));
}

TEST(IrreducibleTest1, true_2)
{
    int p = 2;
    std::vector<int> coeffs_irred = {1, 1, 0, 1, 0, 1, 0, 0, 1};
    Polynomial f_irred(coeffs_irred, p);
    EXPECT_TRUE(is_primitive(f_irred));
}

TEST(IrreducibleTest1, true_3)
{
    int p = 5;
    std::vector<int> coeffs_irred = {2, 4, 0, 0, 0, 1};
    Polynomial f_irred(coeffs_irred, p);
    EXPECT_TRUE(is_primitive(f_irred));
}

TEST(IrreducibleTest1, true_4)
{
    int p = 5;
    std::vector<int> coeffs_irred = {3, 4, 0, 0, 0, 1};
    Polynomial f_irred(coeffs_irred, p);
    EXPECT_TRUE(is_primitive(f_irred));
}

TEST(IrreducibleTest1, false_1)
{
    int p = 2;
    std::vector<int> coeffs_irred = {
        1,
        1,
        0,
        1,
        1,
        0,
        0,
        0,
        1,
    };
    Polynomial f_irred(coeffs_irred, p);
    EXPECT_FALSE(is_primitive(f_irred));
}

TEST(IrreducibleTest1, false_2)
{
    int p = 2;
    std::vector<int> coeffs_irred = {1, 0, 0, 1, 1, 1, 0, 0, 1};
    Polynomial f_irred(coeffs_irred, p);
    EXPECT_FALSE(is_primitive(f_irred));
}

TEST(IrreducibleTest1, false_3)
{
    int p = 5;
    std::vector<int> coeffs_irred = {1, 4, 0, 0, 0, 1};
    Polynomial f_irred(coeffs_irred, p);
    EXPECT_FALSE(is_primitive(f_irred));
}

TEST(IrreducibleTest1, false_4)
{
    int p = 5;
    std::vector<int> coeffs_irred = {4, 4, 0, 0, 0, 1};
    Polynomial f_irred(coeffs_irred, p);
    EXPECT_FALSE(is_primitive(f_irred));
}