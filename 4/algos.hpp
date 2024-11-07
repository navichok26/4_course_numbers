#pragma once
#include <bigNum.hpp>
#include <expected>

std::expected<BN, std::string> Pollard_1(BN n);
