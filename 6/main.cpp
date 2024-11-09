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
  
  auto result = Gelfonds_algorithm(g, p, a);

  if (result) {
    std::cout << "Result: " << *result << std::endl;
  } else {
    std::cerr << "Error: " << result.error() << std::endl;
  }

  return 0;
}
