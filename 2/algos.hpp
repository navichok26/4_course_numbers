#pragma once

#include <bigNum.hpp>
#include <expected>

std::expected<BN, std::string> factorize_with_d(BN n, BN d);
std::expected<BN, std::string> factorize(BN n);