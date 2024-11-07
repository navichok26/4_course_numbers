#pragma once
#include <vector>
#include <expected>
#include <bigNum.hpp>

std::expected<std::vector<BN>, std::string> factorize(BN n);
