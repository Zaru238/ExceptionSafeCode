#!/bin/bash

find -name "*.h" -o -name "*.hpp" -o -name "*.c" -o -name "*.cpp" |
xargs clang-format -style=file -output-replacements-xml |

grep "<replacement " >/dev/null
if [ $? -ne 1 ]; then
  echo "Commit didn't pass clang-format check"
  echo "Please run scripts/apply_clang_format.sh for formatting (run from project dir)"
  exit 1
else
  echo "Clang format check have successfully passed"
fi

exit
