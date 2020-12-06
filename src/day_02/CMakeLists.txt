cmake_minimum_required(VERSION 3.12)

project(day_02
    LANGUAGES CXX
)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

configure_file(input ${CMAKE_CURRENT_BINARY_DIR}/input)

add_library(password
    src/password/password.cpp
)

target_include_directories(password
	PUBLIC
		$<INSTALL_INTERFACE:include>
		$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
	PRIVATE
		${CMAKE_CURRENT_SOURCE_DIR}/src
)

set_target_properties(password PROPERTIES
    CXX_STANDARD 14
    CXX_STANDARD_REQUIRED YES
    CXX_EXTENSIONS NO
)

target_link_libraries(password
    PUBLIC
        passwordpolicy
)

add_library(passwordpolicy
    src/passwordpolicy/passwordpolicy.cpp
)

target_include_directories(passwordpolicy
	PUBLIC
		$<INSTALL_INTERFACE:include>
		$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
	PRIVATE
		${CMAKE_CURRENT_SOURCE_DIR}/src
)

set_target_properties(passwordpolicy PROPERTIES
    CXX_STANDARD 14
    CXX_STANDARD_REQUIRED YES
    CXX_EXTENSIONS NO
)


add_library(day_02
    src/day_02/day_02.cpp
)

target_include_directories(day_02
	PUBLIC
		$<INSTALL_INTERFACE:include>
		$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
	PRIVATE
		${CMAKE_CURRENT_SOURCE_DIR}/src
)

set_target_properties(day_02 PROPERTIES
    CXX_STANDARD 14
    CXX_STANDARD_REQUIRED YES
    CXX_EXTENSIONS NO
)

target_link_libraries(day_02
    PUBLIC
        password
)

add_executable(aoc_day02
    src/main.cpp
)

target_link_libraries(aoc_day02
    PUBLIC
        aoc_common
        day_02
)

set_target_properties(aoc_day02 PROPERTIES
    CXX_STANDARD 14
    CXX_STANDARD_REQUIRED YES
    CXX_EXTENSIONS NO
)
