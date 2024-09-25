#pragma once

#include <bigNum.hpp> // Подключаем BigNum
#include <iostream>

// Функция Эйлера (phi)
BN phi(BN n);

// Тест Миллера-Рабина
bool test_miller_rabin(BN n, int t);

// Оценка вероятности ошибки
void error_phi(BN n, int t);