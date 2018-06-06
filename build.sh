#!/usr/bin/env bash
mkdir bin
cd bin
cmake -DCMAKE_BUILD_TYPE=Release ..
cmake --build . --config Release --target Game
