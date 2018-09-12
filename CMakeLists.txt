cmake_minimum_required(VERSION 3.5)

project(ExceptionSaveCode VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

enable_testing()
find_package(Threads REQUIRED)

include(CTest)

set(SRC_LIST
    "src/CopyableClasses.cpp")

add_executable(testrunner
    "${SRC_LIST}"
    "test/MemoryLeakCheck.cpp")

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

target_include_directories(testrunner PRIVATE src test)

target_compile_options(testrunner PRIVATE -Wextra -pedantic)

target_link_libraries(testrunner PRIVATE ${CMAKE_THREAD_LIBS_INIT} ${CONAN_LIBS})

add_test(NAME MemoryLeakTest COMMAND testrunner)
