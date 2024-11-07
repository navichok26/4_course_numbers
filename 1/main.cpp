#include <iostream>
#include <vector>
#include <cmath>
#include <ranges>
#include "algos.hpp"
#include <millerRabin.hpp>

int main()
{
    BN num;
    
    BN one;
    one = 1;
    num.cin_base10();

    if (num < one) {
        std::cout << "Number must be greater than 1";
        return EXIT_FAILURE;
    }

    if (test_miller_rabin(num, 5)) 
    {
        std::cout << "Miller Rabin: number is prime\n";
        error_phi(num, 5);

        return EXIT_FAILURE; 
    } else {
        std::vector<BN> p = factorize(num);

        num.cout_base10();
        std::cout << " = ";

        // вывод разложения
        for (const auto& factor : std::views::iota(0, static_cast<int>(p.size()))) {
            if (factor != 0) {
                std::cout << " * ";
            }
            p[factor].cout_base10();
        }
        std::cout << std::endl;
    }

    return EXIT_SUCCESS;
}