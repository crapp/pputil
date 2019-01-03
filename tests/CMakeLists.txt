# TODO: This version is speculativ and could be lower. Subject to testing
cmake_minimum_required(VERSION 3.12)
project(pputil_tester VERSION 0.1)

find_path(PPUTIL_HEADER
    pputil.hpp
    PATHS ../include
    NO_DEFAULT_PATH
)

message("Found pputil header in ${PPUTIL_HEADER}")

set(SIMPLE_HEADER
    simple_pputil.hpp
)

set(SIMPLE_SRC
    simple_pputil.cpp
)

add_executable(simple_pputil ${SIMPLE_HEADER} ${SIMPLE_SRC})

target_include_directories(simple_pputil
    PUBLIC ${PPUTIL_HEADER}
)
