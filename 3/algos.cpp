#include "algos.hpp"

std::expected<std::vector<BN>, std::string> factorize(BN n) {
    BN x = n.sqrt();
    vector<BN> d(2);
    BN one, y, z, zero;
    one = 1;
    zero = 0;
    if (n % 2 == zero) {
        return std::unexpected("n is wrong");
    }

    if (x.square() == n) {
        d[0] = x;
        d[1] = x;
        return d;
    }
    while (y.square() != z) {
        x = x + one;
        if (x == (n + one) / 2){
            return std::unexpected("n is prime");
        }
        z = x.square() - n;
        y = z.sqrt();
    }
    d[0] = x + y;
    d[1] = x - y;
    return d;
}