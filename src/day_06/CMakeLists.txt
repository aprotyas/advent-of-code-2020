cmake_minimum_required(VERSION 3.12)

project(day_06
    LANGUAGES CXX
)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/input")
    configure_file(input "${CMAKE_CURRENT_BINARY_DIR}/input")
else()
    message(WARNING "Input file not found")
endif()

add_library(day_06
    src/day_06/day_06.cpp
)

target_include_directories(day_06
	PUBLIC
		$<INSTALL_INTERFACE:include>
		$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
	PRIVATE
		${CMAKE_CURRENT_SOURCE_DIR}/src
)

set_target_properties(day_06 PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED YES
    CXX_EXTENSIONS NO
)

target_link_libraries(day_06
    PUBLIC
    group
)

add_library(group
    src/group/group.cpp
)

target_include_directories(group
	PUBLIC
		$<INSTALL_INTERFACE:include>
		$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
	PRIVATE
		${CMAKE_CURRENT_SOURCE_DIR}/src
)

set_target_properties(group PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED YES
    CXX_EXTENSIONS NO
)

target_link_libraries(group
    PUBLIC
)

add_executable(aoc_day06
    src/main.cpp
)

target_link_libraries(aoc_day06
    PUBLIC
        aoc_common
        day_06
)

set_target_properties(aoc_day06 PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED YES
    CXX_EXTENSIONS NO
)
