cmake_minimum_required(VERSION 3.22)
project(llrt C)

set(CMAKE_C_STANDARD 90)

set(CMAKE_DISABLE_IN_SOURCE_BUILD ON)

file(GLOB CSources source/*.c)
file(GLOB_RECURSE CHeaders headers/*.h)

add_library(llrt STATIC ${CSources} ${CHeaders})

target_compile_options(llrt PUBLIC
        -fstrict-aliasing
        -fmerge-all-constants
        -ffreestanding
        -nostdlib
        -Wall
        -Wextra
        -pedantic
        -Werror
        -O2
        )
target_include_directories(llrt PUBLIC headers)

add_library(rtsvc SHARED ${CSources} ${CHeaders})

target_compile_options(rtsvc PUBLIC
        -fstrict-aliasing
        -fmerge-all-constants
        -ffreestanding
        -nostdlib
        -Wall
        -Wextra
        -pedantic
        -Werror
        -O2
        )
target_include_directories(rtsvc PUBLIC headers)

