#include "algos.hpp"
#include <cmath>
#include <ranges>

int main(void) {
    BN n;
    n.cin_base10();

    auto result = factorize(n);
    if (result) {
        std::cout << "Делители: ";
        for (const auto& factor : std::views::iota(0, static_cast<int>((*result).size()))) {
            if (factor != 0) {
                std::cout << " * ";
            }
            (*result)[factor].cout_base10();
        }
        std::cout << std::endl;
        std::cout << std::endl;
    } else {
        std::cout << "Ошибка: " << result.error() << std::endl;
    }
    return EXIT_SUCCESS;
}