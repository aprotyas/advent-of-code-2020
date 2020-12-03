cmake_minimum_required(VERSION 3.12)
project(advent_of_code_2020
    LANGUAGES CXX
)

#-------------------------------------------------------------------------------
# Specifying Build Type
#-------------------------------------------------------------------------------

set(default_build_type "RelWithDebInfo")
if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
	message(STATUS "Setting build type to '${default_build_type}' as none was specified.")
	set(CMAKE_BUILD_TYPE "${default_build_type}" CACHE STRING "Choose the type of build." FORCE)
	set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS "Debug" "Release" "MinSizeRel" "RelWithDebInfo")
endif()

#-------------------------------------------------------------------------------
# Sources
#-------------------------------------------------------------------------------
add_subdirectory(aoc_common)
add_subdirectory(day_01)
add_subdirectory(day_02)
add_subdirectory(day_03)
