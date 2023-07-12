#!/bin/bash

cmake -DCMAKE_BUILD_TYPE=Release .. && cmake --build . && sudo cmake --install .
