#include "algos.hpp"
#include <iostream>

int main() {
  BN g, p, a;
  int n, tmp;
  std::cout << "Enter g: ";
  g.cin_base10();
  std::cout << "Enter a: ";
  a.cin_base10();
  std::cout << "Enter p: ";
  std::cin >> tmp;
  n = tmp - 1;
  p = tmp;
  std::cout << "Result: " << Gelfonds_algorithm(g, p, n, a) << std::endl;
  return 0;
}
