#!/bin/bash

cd build

cmake -DCOURCEWORK_BUILD_TESTS=ON -DCMAKE_BUILD_TYPE=Release ..
cmake --build .

cd ..
