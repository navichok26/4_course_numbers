#include "algos.hpp"
#include <cmath>

int Gelfonds_algorithm(BN g, int p, BN a) {
  int n = p - 1;
  int h = sqrt(n) + 1;
  BN b = g.pow_bn(h) % p;

  BN giant_step_keys[h + 1];
  int giant_step_values[h + 1];

  for (int i = 0; i <= h; i++) {
    giant_step_values[i] = -1;
  }

  for (int u = 1; u <= h; u++) {
    BN key = b.pow_bn(u) % p;
    bool found = false;

    for (int i = 1; i <= h; i++) {
      if (giant_step_values[i] != -1 && giant_step_keys[i] == key) {
        found = true;
        break;
      }
    }

    if (!found) {
      giant_step_keys[u] = key;
      giant_step_values[u] = u;
    }
  }

  BN small_step_values[h + 1];

  for (int v = 1; v <= h; v++) {
    small_step_values[v] = (a * g.pow_bn(v)) % p;
    for (int i = 1; i <= h; i++) {
      if (giant_step_values[i] != -1 &&
          small_step_values[v] == giant_step_keys[i]) {
        return (h * giant_step_values[i] - v) % n;
      }
    }
  }

  return 0;
}
