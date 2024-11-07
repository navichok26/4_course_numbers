#include "algos.hpp"

int main() 
{
    BN num;

    for (;;) {
        num.cin_base10();

        auto result = Pollard_1(num);

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