#include "algos.hpp"

bool is_irreducible_test1(const Polynomial &f)
{
    int n = f.degree();
    int p = f.p;
    Polynomial u({0, 1}, p);  // u(x) = x

    for (int i = 0; i < n / 2; ++i) {
        u = u.pow(p, f);
        Polynomial d = Polynomial::gcd(f, u - Polynomial({0, 1}, p));
        if (d.degree() >= 1) {
            return false;  // Приводим
        }
    }
    return true;  // Неприводим
}