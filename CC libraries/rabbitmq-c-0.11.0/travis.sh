#!/usr/bin/env bash

build_cmake() {
  mkdir $PWD/_build && cd $PWD/_build
  cmake .. -DCMAKE_INSTALL_PREFIX=$PWD/../_install -DCMAKE_C_FLAGS="-Werror -Wno-implicit-fallthrough" 
  cmake --build . --target install
  ctest -V .
}

build_macos() {
  mkdir $PWD/_build && cd $PWD/_build
  cmake .. -DCMAKE_INSTALL_PREFIX=$PWD/../_install -DCMAKE_C_FLAGS="-Werror" \
    -DOPENSSL_ROOT_DIR="/usr/local/opt/openssl@1.1"
  cmake --build . --target install
  ctest -V .
}

build_format() {
  sudo apt-get install -y clang-format
  ./travis/run-clang-format/run-clang-format.py \
    --clang-format-executable="${PWD}/travis/clang-format.sh" \
    --recursive examples librabbitmq tests tools
}

build_coverage() {
  mkdir $PWD/_build && cd $PWD/_build
  cmake .. -DCMAKE_BUILD_TYPE=Coverage -DCMAKE_INSTALL_PREFIX=$PWD/../_install \
    -DCMAKE_C_FLAGS="-Werror -fprofile-arcs -ftest-coverage"
  cmake --build . --target install
  ctest -V .
  
  pip install --user cpp-coveralls
  coveralls --exclude tests --build-root . --root .. --gcov-options '\-lp'
}

build_asan() {
  mkdir $PWD/_build && cd $PWD/_build
  cmake .. -DCMAKE_BUILD_TYPE=Debug -DCMAKE_INSTALL_PREFIX=$PWD/../_install \
    -DCMAKE_C_FLAGS="-Werror -fsanitize=address,undefined -O1"
  cmake --build . --target install
  ctest -V .
}

build_tsan() {
  mkdir $PWD/_build && cd $PWD/_build
  cmake .. -DCMAKE_BUILD_TYPE=Debug -DCMAKE_INSTALL_PREFIX=$PWD/../_install \
    -DCMAKE_C_FLAGS="-Werror -fsanitize=thread,undefined -O1"
  cmake --build . --target install
  ctest -V .
}

build_scan-build() {
  sudo apt-get install -y clang-tools
  mkdir $PWD/_build && cd $PWD/_build
  scan-build cmake .. -DCMAKE_BUILD_TYPE=Debug \
    -DCMAKE_C_COMPILER=clang \
    -DCMAKE_INSTALL_PREFIX=$PWD/../_install \
    -DCMAKE_C_FLAGS="-Werror"
  scan-build make install
}

if [ "$#" -ne 1 ]; then
  echo "Usage: $0 {cmake|macos|format|coverage|asan|tsan|scan-build}"
  exit 1
fi

set -e  # exit on error.
set -x  # echo commands.

eval "build_$1"
