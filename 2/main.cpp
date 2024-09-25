#include "algos.hpp"
#include <iostream>

int main(void) {
    BN n;
    n.cin_base10();

    std::expected<BN, std::string> result = factorize(n);
    if (result) {
        std::cout << "Делитель: ";
        (*result).cout_base10();
        std::cout << std::endl;
    } else {
        std::cout << "Ошибка: " << result.error() << std::endl;
    }
    return EXIT_SUCCESS;
}