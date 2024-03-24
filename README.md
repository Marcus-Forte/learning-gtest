# Learning GTest

This is a very simple example project that uses GTest and GMock to introduce software testing concepts.

## Dependencies
- [GTest and GMock](https://github.com/google/googletest)

Install it either locally or on your system. If locally installed, make sure to adjust line `21` on CMakeLists.txt with `PATHS`, or set `CMAKE_PREFIX_PATH` accordingly.

## Usage
- mkdir build
- cd build
- cmake .. -DBUILD_TESTS=ON
- cmake --build .
- `ctest` or `./tests`