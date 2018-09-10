[![Build Status](https://travis-ci.org/Morheit/DoubleDispatch.svg?branch=master)](https://travis-ci.org/Morheit/DoubleDispatch)

# DoubleDispatch #

Example of use "Double Dispatch" pattern to avoid `static_cast` restrictions

## Platform ##

* Linux
* macOS

## Requirements ##

* GNU-compatible Make
* POSIX-standard shell
* A C++11-standard-compliant compiler

## Build ##

### Build commands ###

By default used clang compiler and debug mode.

Run in project root to build debug version with clang

make clang

To build release version with gcc run the following command

make gcc

## Run ##

Run from build directory

`ctest`

or

`ctest TypeConversionTest`
