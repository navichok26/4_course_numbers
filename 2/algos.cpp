#include "algos.hpp"

std::expected<BN, std::string> factorize(BN n, BN d) {
    if (n % 2 == 0) {
        return std::unexpected("n % 2 == 0");
    }

    if (d % 2 == 0) {
        return std::unexpected("d % 2 == 0");
    }

    return BN(1, 0)
}