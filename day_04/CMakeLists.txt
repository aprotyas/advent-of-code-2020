cmake_minimum_required(VERSION 3.12)

project(day_04
    LANGUAGES CXX
)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

configure_file(input ${CMAKE_CURRENT_BINARY_DIR}/input)

add_library(day_04
    src/day_04/day_04.cpp
)

target_include_directories(day_04
	PUBLIC
		$<INSTALL_INTERFACE:include>
		$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
	PRIVATE
		${CMAKE_CURRENT_SOURCE_DIR}/src
)

set_target_properties(day_04 PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED YES
    CXX_EXTENSIONS NO
)

target_link_libraries(day_04
    PUBLIC
        passport
)

add_library(passport
    src/passport/passport.cpp
)

target_include_directories(passport
	PUBLIC
		$<INSTALL_INTERFACE:include>
		$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
	PRIVATE
		${CMAKE_CURRENT_SOURCE_DIR}/src
)

set_target_properties(passport PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED YES
    CXX_EXTENSIONS NO
)

target_link_libraries(passport
    PUBLIC
)

add_executable(aoc_day04
    src/main.cpp
)

target_link_libraries(aoc_day04
    PUBLIC
        aoc_common
        day_04
)

set_target_properties(aoc_day04 PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED YES
    CXX_EXTENSIONS NO
)
