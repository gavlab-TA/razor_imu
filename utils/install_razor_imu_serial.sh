#!/bin/bash
mkdir ../build/
cd ../build
cmake -DCMAKE_BUILD_TYPE=Release .. && cmake --build . && sudo cmake --install .
