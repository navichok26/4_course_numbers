#include <bigNum.hpp>
#include <expected>

std::expected<int, std::string> Gelfonds_algorithm(BN g, int p, BN a);
