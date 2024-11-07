#pragma once
#include <bigNum.hpp>
#include <expected>

std::expected<BN, std::string> Pollard_2(BN n);