#include "algos.hpp"
#include <cmath>

std::expected<int, std::string> Gelfonds_algorithm(BN g, int p, BN a) {
  int n = p - 1;
  int h = sqrt(n) + 1;
  BN b = g.pow_bn(h) % p;

  BN giant_step_values[h + 1];

  for (int u = 1; u <= h; u++) {
    BN value = b.pow_bn(u) % p;
    giant_step_values[u] = value;
  }

  BN small_step_value;

  for (int v = 1; v <= h; v++) {
    small_step_value = (a * g.pow_bn(v)) % p;
    for (int u = 1; u <= h; u++) {
      if (giant_step_values[u] != -1 &&
          small_step_value == giant_step_values[u]) {
        return (h * u - v) % n;
      }
    }
  }

  return std::unexpected("Not found");
}
// четверг 12:25 - 210 аудитория пара в паралель с самохиной
// пятница 10:35 - 330 аудитория