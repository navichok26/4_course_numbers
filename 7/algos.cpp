#include "algos.hpp"

#include <vector>

#include "bigNum.hpp"

bool in_S1(BN &x)
{
    BN one;
    one = 1;
    return x % 3 == one;
}

bool in_S2(BN &x)
{
    BN two;
    two = 2;

    return x % 3 == two;
}

bool in_S3(BN &x)
{
    BN zero;
    zero = 0;

    return x % 3 == zero;
}

std::tuple<BN, BN, BN> F(BN &x, BN &u, BN &v, BN &g, BN &a, int p)
{
    BN new_x, new_u, new_v;
    BN one, two;
    one = 1;
    two = 2;

    if (in_S1(x)) {
        new_x = (a * x) % p;
        new_u = u;
        new_v = (v + one) % (p - 1);
    } else if (in_S2(x)) {
        new_x = (x * x) % p;
        new_u = (two * u) % (p - 1);
        new_v = (two * v) % (p - 1);
    } else if (in_S3(x)) {
        new_x = (g * x) % p;
        new_u = (u + one) % (p - 1);
        new_v = v;
    }

    return {new_x, new_u, new_v};
}

std::expected<int, std::string> pollard_pmethod(BN g, int p, BN a)
{
    int n = p - 1;
    BN x1, x2;
    x1 = 1, x2 = 1;
    BN y1, y2;
    y1 = 0, y2 = 0;
    BN b1, b2;
    b1 = 0, b2 = 0;

    BN zero;
    zero = 0;
    while (true) {
        // Шаг черепахи (медленное обновление)
        std::tie(x1, y1, b1) = F(x1, y1, b1, g, a, p);
        // Шаг зайца (быстрое обновление: два шага)
        std::tie(x2, y2, b2) = F(x2, y2, b2, g, a, p);
        std::tie(x2, y2, b2) = F(x2, y2, b2, g, a, p);

        if (x1 == x2) {
            BN r = b1.mod_sub(b2, n);
            if (r == zero) {
                return std::unexpected("Solution not found.");
            }

            BN temp;
            temp = n;

            BN y_diff = y2.mod_sub(y1, n);
            BN d = r.gcd(temp);
            BN n_div_d = temp / d;
            BN r_div_d = r / d;
            BN y_div_d = y_diff / d;
            BN r_inv = r_div_d.mod_inverse(n_div_d);
            if (r_inv == zero) {
                throw std::runtime_error("Обратный элемент не существует.");
            }
            BN result = (y_div_d * r_inv) % n_div_d;

            std::vector<int> solutions;
            for (BN k = BN(0); k < d; k = k + BN(1)) {
                BN possible_result = (result + k * n_div_d) % n;
                // Проверяем, является ли possible_result решением
                if (g.pow_mod(possible_result, p) == a) {
                    solutions.push_back(possible_result.to_base());
                }
            }

            if (solutions.empty()) {
                throw std::runtime_error("Решение не найдено.");
            }

            // Возвращаем одно из найденных решений
            return solutions[0];
        }
    }
}