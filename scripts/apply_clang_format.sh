#!/bin/bash

find -name "*.h" -o -name "*.hpp" -o -name "*.c" -o -name "*.cpp" |
xargs clang-format -i

echo "Done"
