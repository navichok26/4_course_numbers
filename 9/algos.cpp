#include "algos.hpp"

#include <cmath>

#include <vector>

bool is_irreducible_test2(const Polynomial &f)
{
    int n = f.degree();
    int p = f.p;
    Polynomial x_poly({0, 1}, p);  // Полином x

    // Вычисляем u = x^{p^n} mod f(x)
    Polynomial u = x_poly.pow(pow_mod(p, n, f.p), f);

    Polynomial g = Polynomial::gcd(f, u - x_poly);
    if (g.degree() >= 1) {
        return false;  // Приводим
    }

    // Находим простые делители степени n
    std::vector<int> prime_factors = get_prime_factors(n);

    for (int q : prime_factors) {
        int exponent = pow_mod(p, n / q, f.p);
        Polynomial u_i = x_poly.pow(exponent, f);
        Polynomial d = Polynomial::gcd(f, u_i - x_poly);
        if (d.degree() >= 1 && d.degree() < n) {
            return false;  // Приводим
        }
    }
    return true;  // Неприводим
}

// Функция для нахождения простых делителей числа n
std::vector<int> get_prime_factors(int n)
{
    std::vector<int> factors;
    int num = n;
    for (int i = 2; i * i <= num; ++i) {
        if (num % i == 0) {
            factors.push_back(i);
            while (num % i == 0)
                num /= i;
        }
    }
    if (num > 1) {
        factors.push_back(num);
    }
    return factors;
}

// Функция для быстрого возведения в степень по модулю
uint64_t pow_mod(uint64_t base, uint64_t exponent, uint64_t mod)
{
    uint64_t result = 1;
    base = base % mod;
    while (exponent > 0) {
        if (exponent & 1)
            result = (result * base) % mod;

        exponent >>= 1;
        base = (base * base) % mod;
    }
    return result;
}