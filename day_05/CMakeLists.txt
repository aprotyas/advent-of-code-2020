cmake_minimum_required(VERSION 3.12)

project(day_05
    LANGUAGES CXX
)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

configure_file(input ${CMAKE_CURRENT_BINARY_DIR}/input)

add_library(day_05
    src/day_05/day_05.cpp
)

target_include_directories(day_05
	PUBLIC
		$<INSTALL_INTERFACE:include>
		$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
	PRIVATE
		${CMAKE_CURRENT_SOURCE_DIR}/src
)

set_target_properties(day_05 PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED YES
    CXX_EXTENSIONS NO
)

target_link_libraries(day_05
    PUBLIC
)

add_executable(aoc_day05
    src/main.cpp
)

target_link_libraries(aoc_day05
    PUBLIC
        aoc_common
        day_05
)

set_target_properties(aoc_day05 PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED YES
    CXX_EXTENSIONS NO
)
