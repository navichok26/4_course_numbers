#pragma once

#include <cstdlib>
#include <cstring>
#include <ctime>

#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <string>

typedef unsigned short BASE;
typedef unsigned int DBASE;
#define BASE_SIZE sizeof(BASE) * 8

using namespace std;

class BN {
public:
    int len;
    int maxlen;
    BASE *coef;

    BN();
    explicit BN(int ml, int t);
    BN(const BN &);
    ~BN();
    BN(const BASE &);

    BN &operator=(const BN &);
    BN &operator=(const BASE &);

    bool operator==(const BN &);
    bool operator>=(const BN &);
    bool operator<=(const BN &);
    bool operator<(const BN &);
    bool operator>(const BN &);
    bool operator!=(const BN &);

    BN operator+(const BN &);
    BN &operator+=(const BN &);
    BN operator-(const BN &);
    BN &operator-=(const BN &);
    BN operator*(const BASE &);
    BN &operator*=(const BASE &);
    BN operator*(const BN &);
    BN &operator*=(const BN &);
    BN operator/(const BASE &);
    BN operator%(const BASE &);
    BN operator/(const BN &);
    BN operator%(const BN &);
    BN sqrt();
    BN root(int n);
    BN pow_bn(int y);
    BN square();
    BN gcd(const BN &b);
    int log_bn(BN q);

    void cout_base10();
    void cin_base10();

    double to_double() const;
    BN pow_mod(BN &exponent, BN &mod) const;
    BN pow_mod(BN &exponent, BASE mod) const;
    BN mod_sub(const BN &other, int modulus);
    BN mod_inverse(const BN &modulus);

    BASE to_base() const;

    static BN random_bound(BN a, BN b);

    friend BN operator*(BASE num, BN bNum)
    {
        return bNum * num;
    }
    friend ostream &operator<<(ostream &, const BN &);
    friend istream &operator>>(istream &, BN &);
};