#include "algos.hpp"

uint64_t int_pow(uint64_t base, uint64_t exponent)
{
    uint64_t result = 1;
    while (exponent > 0) {
        if (exponent & 1)
            result *= base;
        exponent >>= 1;
        base *= base;
    }
    return result;
}

// Функция для факторизации числа на простые множители
std::vector<uint64_t> get_prime_factors(uint64_t n)
{
    std::vector<uint64_t> factors;
    uint64_t num = n;
    for (uint64_t i = 2; i * i <= num; ++i) {
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

// Тест на непримитивность полинома
bool is_primitive(const Polynomial &f)
{
    int n = f.degree();
    int p = f.p;  // Предполагается, что модуль поля сохранён в переменной p

    // Вычисляем m = p^n - 1
    uint64_t m = int_pow(p, n) - 1;

    // Находим простые делители числа m
    std::vector<uint64_t> prime_factors = get_prime_factors(m);

    Polynomial x_poly({0, 1}, p);  // Полином x

    for (uint64_t q : prime_factors) {
        uint64_t exponent = m / q;
        Polynomial r = x_poly.pow(exponent, f);
        if (r == Polynomial({1}, p)) {
            // Полином не является примитивным
            return false;
        }
    }

    // Полином является примитивным
    return true;
}