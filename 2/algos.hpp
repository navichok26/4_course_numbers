#pragma once

#include <bigNum.hpp>
#include <expected>

std::expected<BN, std::string> factorize(BN n, BN d);