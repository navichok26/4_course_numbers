#pragma once

#include <ctime>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <stdexcept>
#include <algorithm>
#include <string>

typedef unsigned short BASE;
typedef unsigned int DBASE;
#define BASE_SIZE sizeof(BASE)*8

using namespace std;

class BN {
public:
    int len;
    int maxlen;
    BASE *coef;

    BN();
    explicit BN(int ml, int t);
    BN(const BN&);
    ~BN();
    BN(const BASE&);

    BN& operator = (const BN&);
    BN& operator = (const BASE&);

    bool operator == (const BN&);
    bool operator >= (const BN&);
    bool operator <= (const BN&);
    bool operator < (const BN&);
    bool operator > (const BN&);
    bool operator != (const BN&);

    BN operator + (const BN&);
    BN& operator += (const BN&);
    BN operator - (const BN&);
    BN& operator -= (const BN&);
    BN operator * (const BASE&);
    BN& operator *= (const BASE&);
    BN operator * (const BN&);
    BN& operator *= (const BN&);
    BN operator / (const BASE&);
    BN operator % (const BASE&);
    BN operator / (const BN&);
    BN operator % (const BN&);
    BN sqrt();
    BN root(int n);
    BN pow_bn(int y);
    BN square();
    BN gcd(const BN& b);
    int log_bn(BN q);


    void cout_base10();
    void cin_base10();

    double to_double() const;
    BN pow_mod(BN& exponent, BN& mod) const;
    

    static BN random_bound(BN a, BN b);


    friend BN operator*(BASE num, BN bNum) { return bNum * num; }
    friend ostream& operator << (ostream &, const BN &);
    friend istream& operator >> (istream &, BN &);
};