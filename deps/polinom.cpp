// polinom.cpp

#include "polinom.hpp"

#include <algorithm>
#include <iostream>
#include <stdexcept>

// Конструктор полинома
Polynomial::Polynomial(const std::vector<int> &c, int mod)
    : coeffs(c)
    , p(mod)
{
    normalize();
}

// Нормализация: удаление старших нулевых коэффициентов и приведение коэффициентов по модулю p
void Polynomial::normalize()
{
    // Приводим все коэффициенты по модулю p
    for (auto &coef : coeffs) {
        coef = ((coef % p) + p) % p;
    }
    // Удаляем старшие нулевые коэффициенты
    while (!coeffs.empty() && coeffs.back() == 0) {
        coeffs.pop_back();
    }
    // Если полином стал пустым, добавляем нулевой коэффициент
    if (coeffs.empty()) {
        coeffs.push_back(0);
    }
}

// Возврат степени полинома
int Polynomial::degree() const
{
    if (coeffs.empty() || (coeffs.size() == 1 && coeffs[0] == 0)) {
        return -1;  // Степень нулевого полинома
    }
    return static_cast<int>(coeffs.size()) - 1;
}

// Вычитание полиномов по модулю p
Polynomial Polynomial::operator-(const Polynomial &other) const
{
    std::vector<int> result(std::max(coeffs.size(), other.coeffs.size()), 0);
    for (size_t i = 0; i < coeffs.size(); ++i) {
        result[i] = coeffs[i];
    }
    for (size_t i = 0; i < other.coeffs.size(); ++i) {
        result[i] = ((result[i] - other.coeffs[i]) % p + p) % p;
    }
    return Polynomial(result, p);
}

// Умножение полиномов по модулю p
Polynomial Polynomial::operator*(const Polynomial &other) const
{
    std::vector<int> result(coeffs.size() + other.coeffs.size() - 1, 0);
    for (size_t i = 0; i < coeffs.size(); ++i) {
        for (size_t j = 0; j < other.coeffs.size(); ++j) {
            int idx = i + j;
            result[idx] = (result[idx] + coeffs[i] * other.coeffs[j]) % p;
        }
    }
    return Polynomial(result, p);
}

// Остаток от деления одного полинома на другой по модулю p
Polynomial Polynomial::operator%(const Polynomial &divisor) const
{
    Polynomial dividend = *this;
    Polynomial div = divisor;
    dividend.normalize();
    div.normalize();

    if (div.degree() < 0) {
        throw std::invalid_argument("Division by zero polynomial.");
    }

    // Проверка на нулевое делимое
    if (dividend.coeffs.empty() || (dividend.coeffs.size() == 1 && dividend.coeffs[0] == 0)) {
        return dividend;  // Остаток от деления нулевого полинома - нулевой полином
    }

    while (dividend.degree() >= div.degree()) {
        dividend.normalize();  // Удаляем возможные нулевые старшие коэффициенты

        if (dividend.coeffs.empty() || dividend.degree() < div.degree()) {
            break;  // Делимое стало нулевым или его степень меньше степени делителя
        }

        int dividendLeadingCoef = dividend.coeffs.back();
        int divisorLeadingCoef = div.coeffs.back();

        if (divisorLeadingCoef == 0) {
            throw std::runtime_error("Leading coefficient of divisor is zero.");
        }

        int inv_leading_coef = inverse(divisorLeadingCoef, p);
        if (inv_leading_coef == 0) {
            throw std::runtime_error("Leading coefficient of divisor has no inverse.");
        }

        int coef = dividendLeadingCoef * inv_leading_coef % p;
        if (coef < 0)
            coef += p;  // Обеспечиваем положительный коэффициент

        int deg_diff = dividend.degree() - div.degree();
        std::vector<int> temp_coeffs(deg_diff + 1, 0);
        temp_coeffs.back() = coef;
        Polynomial temp(temp_coeffs, p);

        dividend = dividend - (div * temp);
        // dividend.normalize(); // Уже вызвали normalize() в начале цикла
    }
    return dividend;
}

// Наибольший общий делитель двух полиномов (алгоритм Евклида)
Polynomial Polynomial::gcd(const Polynomial &a, const Polynomial &b)
{
    if (a.p != b.p) {
        throw std::invalid_argument("Polynomials must have the same modulus p.");
    }

    if (b.coeffs.empty() || (b.coeffs.size() == 1 && b.coeffs[0] == 0)) {
        // Нормализуем НОД так, чтобы старший коэффициент был равен 1
        int leading_coef = a.coeffs.back();
        int inv_leading_coef = inverse(leading_coef, a.p);  // Используем a.p
        if (inv_leading_coef == 0) {
            throw std::runtime_error("Leading coefficient has no inverse.");
        }
        // Умножаем полином на обратный старший коэффициент для нормализации
        return (a * Polynomial({inv_leading_coef}, a.p));
    }
    return gcd(b, a % b);
}

// Возведение полинома в степень по модулю другого полинома (быстрое возведение в степень)
Polynomial Polynomial::pow(int exponent, const Polynomial &mod_poly) const
{
    Polynomial result({1}, p);  // Результат = 1
    Polynomial base = *this % mod_poly;

    while (exponent > 0) {
        if (exponent % 2 == 1) {
            result = (result * base) % mod_poly;
        }
        base = (base * base) % mod_poly;
        exponent /= 2;
    }
    return result;
}

// Вывод полинома
void Polynomial::print() const
{
    bool first = true;
    for (int i = static_cast<int>(coeffs.size()) - 1; i >= 0; --i) {
        if (coeffs[i] != 0) {
            if (!first) {
                std::cout << " + ";
            }
            if (i == 0 || coeffs[i] != 1) {
                std::cout << coeffs[i];
                if (i >= 1)
                    std::cout << "*";
            }
            if (i >= 1) {
                std::cout << "x";
                if (i >= 2) {
                    std::cout << "^" << i;
                }
            }
            first = false;
        }
    }
    if (coeffs.empty() || (coeffs.size() == 1 && coeffs[0] == 0)) {
        std::cout << "0";
    }
    std::cout << std::endl;
}

// Вычисление обратного элемента в поле Z_p с помощью расширенного алгоритма Евклида
int Polynomial::inverse(int a, int mod)
{
    int m0 = mod, t, q;
    int x0 = 0, x1 = 1;

    if (mod == 1)
        return 0;
    a = (a % mod + mod) % mod;

    while (a > 1) {
        // q - частное
        q = a / mod;
        t = mod;

        // m - остаток от деления
        mod = a % mod;
        a = t;

        t = x0;
        x0 = x1 - q * x0;
        x1 = t;
    }

    // Обратный элемент
    if (x1 < 0)
        x1 += m0;

    return x1;
}