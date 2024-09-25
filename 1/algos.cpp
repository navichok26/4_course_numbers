#include "algos.hpp"
#include <vector>

int add(int a, int b) {
    return a + b;
}


std::vector<BN> factorize(const BN& num)
{
    BN n = num;
    BN n_sqrt = n.sqrt();

    std::vector<BN> p;
    int k = 0;

    BN zero, one, two, six; 
    zero = 0; 
    one = 1; 
    two = 2;
    six = 6; 

    while (n % 2 == zero) {
        p.push_back(two);
        n = n / 2;
    }
    

    std::vector<BN> d(3);
    d[0] = 3;
    d[1] = 5;
    d[2] = 7;

    while (n != one) {
        BN r = n % d[k];
        BN q = n / d[k];
        if (r == zero) {
            p.push_back(d[k]);
            n = q;
            continue;
        } 
        if (q > d[k] && d[k] <= n_sqrt) {
            k++;
            if (k > 2) {
                d.push_back(d[k - 2] + six);
            }
        } else {
            p.push_back(n);
            return p;
        }
    }
    return p;
}