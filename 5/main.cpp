#include "algos.hpp"

int main()
{
    BN num;
    // num = 8;
    // BN q;
    // q = 2;
    // auto res =  num.log_bn(q);
    // std::cout << res << std::endl;

    for (;;) {
        num.cin_base10();

        auto result = Pollard_2(num);

        if (result) {
            std::cout << "Делитель: ";
            (*result).cout_base10();
            std::cout << std::endl;
        } else {
            std::cout << "Ошибка: " << result.error() << std::endl;
        }
        std::cout << endl << endl;
    }
}