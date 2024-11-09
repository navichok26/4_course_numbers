#!/bin/bash

rm -rf build

cmake -S . -B build -DCMAKE_CXX_COMPILER=/usr/bin/clang++-17 \
    -DCMAKE_C_COMPILER=/usr/bin/clang-17 \

make -C build