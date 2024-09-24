#include <iostream>
#include <vector>
#include "bigNum.h"
#include "millerRabin.h"
#include <cmath>
#include <ranges>


std::vector<BN> factorize(const BN& num)
{
    BN n = num;
    BN n_sqrt = n.sqrt();

    std::vector<BN> p;
    int k = 0;

    BN zero, one, two, six; 
    zero = 0; 
    one = 1; 
    two = 2;
    six = 6; 

    while (n % 2 == zero) {
        p.push_back(two);
        n = n / 2;
    }
    
    std::vector<BN> d(3);
    d[0] = 3;
    d[1] = 5;
    d[2] = 7;

    while (n != one) {
        BN r = n % d[k];
        BN q = n / d[k];
        if (r == zero) {
            p.push_back(d[k]);
            n = q;
            continue;
        } 
        if (q > d[k] && d[k] <= n_sqrt) {
            k++;
            if (k > 2) {
                d.push_back(d[k - 2] + six);
            }
        } else {
            p.push_back(n);
            return p;
        }
    }
    return p;
}

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

    if (test_miller_rabin(num, 15)) 
    {
        std::cout << "Miller Rabin: number is prime\n";
        error_phi(num, 15);

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