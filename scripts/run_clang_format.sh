#!/bin/bash

if [ -x "$(command -v clang-format-16)" ]; then
  find -iname '*.h' -o -iname '*.cpp' -not -path "./build/*" | xargs clang-format-16 -i
else
  echo "clang-format-16 is not installed"
fi
