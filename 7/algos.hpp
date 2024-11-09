#include <string>

#include <stdint.h>
#include <stdio.h>

#include <bigNum.hpp>
#include <expected>

std::expected<int, std::string> pollard_pmethod(BN g, int p, BN a);