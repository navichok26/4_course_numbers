#include "algos.hpp"

BN f(BN x, BN n) 
{
    BN result = x;
    BN one;
    one = 1;
    result = (result*result + one) % n;
    return result;
}


std::expected<BN, std::string> Pollard_1(BN n)
{
    BN two, zero;
    two = 2;

    if (n % 2 == zero) 
        return two;

    BN a, b, d, one;
    a = 2;
    b = 2;
    one = 1;
    do {
        a = f(a, n);
        b = f(f(b, n), n);

        if (a == b) {
            return std::unexpected("No result");
        }
        if (a > b) {
            d = n.gcd(a - b);
        } else {
            d = n.gcd(b - a);
        }
    } while (d == 1);
    return d;
}
