#include "algos.hpp"

std::expected<BN, std::string> factorize_with_d(BN n, BN d) {
    if (n % 2 == 0) {
        return std::unexpected("n % 2 == 0");
    }

    if (d % 2 == 0) {
        return std::unexpected("d % 2 == 0");
    }

    if (d < (2 * n.root(3) + 1)) {
        return std::unexpected("d < (2 * n.root(3) + 1)");
    }


    BN r;
    BN r1 = n % d;
    BN r2 = n % (d-2);

    BN q = 4 * ((n / (d - 2)) - (n / d));

    BN s = n.root(2);

    do {
        d += 2;
        if (d > s) {
            return std::unexpected("Делителя нет");
        }
        if ((r1 * 2) + q < r2) {
            r = ((r1 * 2) + q + d) - r2;
            r2 = r1;
            r1 = r;
            q += 4;
        }
        else {
            r = ((r1 * 2) + q) - r2;
            r2 = r1;
            r1 = r;
        }
        while (r1 >= d) {
            r1 -= d;
            q -= 4; 
        }
    } while (r1 != 0);

    return d;
}

std::expected<BN, std::string> factorize(BN n) {
    BN d = n.root(3) * 2 + 1;
    return factorize_with_d(n, d);
}