#pragma once

#include <vector>

class Polynomial {
public:
    std::vector<int> coeffs;  // Коэффициенты от младшего к старшему
    int p;                    // Модуль

    Polynomial(const std::vector<int> &c, int mod);

    void normalize();
    int degree() const;

    Polynomial operator-(const Polynomial &other) const;
    Polynomial operator*(const Polynomial &other) const;
    Polynomial operator%(const Polynomial &divisor) const;

    static Polynomial gcd(const Polynomial &a, const Polynomial &b);
    Polynomial pow(int exponent, const Polynomial &mod_poly) const;

    void print() const;

private:
    static int inverse(int a, int mod);
};