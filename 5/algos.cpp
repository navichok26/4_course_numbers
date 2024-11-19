#include "algos.hpp"

#include <cmath>
#include <cstdint>

#include <millerRabin.hpp>

bool is_prime(int n)
{
    if (n <= 1) {
        return false;
    }
    if (n == 2) {
        return true;
    }
    if (n % 2 == 0) {
        return false;
    }

    int limit = std::sqrt(n);
    for (int i = 3; i <= limit; i += 2) {
        if (n % i == 0) {
            return false;
        }
    }

    return true;
}

std::expected<BN, std::string> Pollard_2(BN n)
{
    uint64_t B = 100;
    BN a, two, one, zero;
    one = 1;
    two = 2;
    a = BN::random_bound(two, n - two);
    BN d = a.gcd(n);
    if (d > one)
        return d;
    uint64_t q = 2;
    while (q < B) {
        if (is_prime(q)) {
            uint64_t e = n.log_bn(q);
            double result = std::pow(q, e);
            // std::cout << "res:" << result << std::endl;
            uint64_t tmp = static_cast<uint64_t>(result);
            BN for_pow;
            for_pow = tmp;
            // std::cout << "tmp:" << tmp << std::endl;
            a = a.pow_mod(for_pow, n);
        }
        q++;
        // std::cout << "q:" << q << std::endl;
    }
    if (a == one) {
        return std::unexpected("otkasz");
    } else {
        d = (a - 1).gcd(n);
    }

    if (d == one) {
        return std::unexpected("otkasz");
    }
    return d;
}
