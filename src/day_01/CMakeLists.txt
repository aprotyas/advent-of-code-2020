cmake_minimum_required(VERSION 3.12)

project(day_01
    LANGUAGES CXX
)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

configure_file(input ${CMAKE_CURRENT_BINARY_DIR}/input)

add_library(day_01
    src/day_01/day_01.cpp
)

target_include_directories(day_01
	PUBLIC
		$<INSTALL_INTERFACE:include>
		$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
	PRIVATE
		${CMAKE_CURRENT_SOURCE_DIR}/src
)

set_target_properties(day_01 PROPERTIES
    CXX_STANDARD 14
    CXX_STANDARD_REQUIRED YES
    CXX_EXTENSIONS NO
)

add_executable(aoc_day01
    src/main.cpp
)

target_link_libraries(aoc_day01
    PUBLIC
        aoc_common
        day_01
)

set_target_properties(aoc_day01 PROPERTIES
    CXX_STANDARD 14
    CXX_STANDARD_REQUIRED YES
    CXX_EXTENSIONS NO
)
