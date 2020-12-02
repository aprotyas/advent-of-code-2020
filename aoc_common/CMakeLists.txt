cmake_minimum_required(VERSION 3.12)
project(aoc_common
	LANGUAGES CXX
	VERSION 0.1.0
)

#-------------------------------------------------------------------------------
# C++ Library
#-------------------------------------------------------------------------------
add_library(aoc_common
	src/utils/utils.cpp
)

target_include_directories(aoc_common
	PUBLIC
		$<INSTALL_INTERFACE:include>
		$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
	PRIVATE
		${CMAKE_CURRENT_SOURCE_DIR}/src
)

set_target_properties(aoc_common PROPERTIES
	CXX_STANDARD 14
	CXX_STANDARD_REQUIRED YES
	CXX_EXTENSIONS NO
)
