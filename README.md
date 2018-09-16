[![Build Status](https://travis-ci.org/Zaru238/ExceptionSafeCode.svg?branch=master)](https://travis-ci.org/Zaru238/ExceptionSafeCode)

# ExceptionSafeCode #

Test project

## Platform ##

* Linux

## Requirements ##

* CMake 3.5 or higher
* Clang-6.0
* Clang-format-6.0
* Conan
* Valgrind

### Build commands ###

* make release
* make debug
* make apply_format
* make clean

## Run ##

Run from build directory

`ctest`

or

`ctest TypeConversionTest`

### TODO List ###

* move test executing to the separate make targets make check debug and make check release
* move clang format settings file to the tools folder
* investigate how conan build works and try to improve conan usage
