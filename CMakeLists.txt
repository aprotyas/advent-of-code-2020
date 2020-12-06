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

if(NOT DEFINED SRC_DIR)
    message(STATUS "SRC_DIR not defined: setting to `src`")
    set(SRC_DIR "src")
endif()

macro(subdirlist RESULT)
    file(GLOB CHILDREN RELATIVE "${CMAKE_CURRENT_SOURCE_DIR}/${SRC_DIR}" "${CMAKE_CURRENT_SOURCE_DIR}/${SRC_DIR}/*")
    set(DIR_LIST "")
    foreach(CHILD ${CHILDREN})
        if(IS_DIRECTORY "${SRC_DIR}/${CHILD}")
            message(STATUS "Adding ${CHILD} to subdirectories")
            list(APPEND DIR_LIST "${CHILD}")
        endif()
    endforeach()
    set(${RESULT} ${DIR_LIST})
endmacro()

subdirlist(SUBDIRS)

foreach(SUBDIR ${SUBDIRS})
    add_subdirectory("${SRC_DIR}/${SUBDIR}" ${SUBDIR})
endforeach()
