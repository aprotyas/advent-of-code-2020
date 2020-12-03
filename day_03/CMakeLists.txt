cmake_minimum_required(VERSION 3.12)

project(day_03
    LANGUAGES CXX
)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

configure_file(input ${CMAKE_CURRENT_BINARY_DIR}/input)

add_library(day_03
    src/day_03/day_03.cpp
)

target_include_directories(day_03
	PUBLIC
		$<INSTALL_INTERFACE:include>
		$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
	PRIVATE
		${CMAKE_CURRENT_SOURCE_DIR}/src
)

set_target_properties(day_03 PROPERTIES
    CXX_STANDARD 14
    CXX_STANDARD_REQUIRED YES
    CXX_EXTENSIONS NO
)

target_link_libraries(day_03
    PUBLIC
        world
)

add_library(world
    src/world/world.cpp
)

target_include_directories(world
	PUBLIC
		$<INSTALL_INTERFACE:include>
		$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
	PRIVATE
		${CMAKE_CURRENT_SOURCE_DIR}/src
)

set_target_properties(world PROPERTIES
    CXX_STANDARD 14
    CXX_STANDARD_REQUIRED YES
    CXX_EXTENSIONS NO
)

target_link_libraries(world
    PUBLIC
        location
)

add_library(location
    src/location/location.cpp
)

target_include_directories(location
	PUBLIC
		$<INSTALL_INTERFACE:include>
		$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
	PRIVATE
		${CMAKE_CURRENT_SOURCE_DIR}/src
)

set_target_properties(location PROPERTIES
    CXX_STANDARD 14
    CXX_STANDARD_REQUIRED YES
    CXX_EXTENSIONS NO
)

target_link_libraries(location
    PUBLIC
)

add_executable(aoc_day03
    src/main.cpp
)

target_link_libraries(aoc_day03
    PUBLIC
        aoc_common
        day_03
)

set_target_properties(aoc_day03 PROPERTIES
    CXX_STANDARD 14
    CXX_STANDARD_REQUIRED YES
    CXX_EXTENSIONS NO
)
