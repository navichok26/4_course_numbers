#include "algos.hpp"
#include <iostream>

int main() {
  BN g, a;
  int p;
  std::cout << "Enter g: ";
  g.cin_base10();
  std::cout << "Enter a: ";
  a.cin_base10();
  std::cout << "Enter p: ";
  std::cin >> p;
  std::cout << "Result: " << Gelfonds_algorithm(g, p, a) << std::endl;
  return 0;
}
