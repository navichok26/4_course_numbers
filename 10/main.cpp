#include <iostream>

#include "algos.hpp"
#include "polinom.hpp"

int main()
{
    int p = 2;  // Поле Z_2

    // Пример неприводимого многочлена f(x) = x^3 + x + 1
    std::vector<int> coeffs = {1, 1, 0, 1};  // Коэффициенты от x^0 до x^3
    Polynomial f(coeffs, p);

    std::cout << "Тестирование полинома: ";
    f.print();

    if (is_primitive(f)) {
        std::cout << "Многочлен является примитивным.\n";
    } else {
        std::cout << "Многочлен не является примитивным.\n";
    }

    return 0;
}