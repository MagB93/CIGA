cmake_minimum_required( VERSION 3.2 )

project( CIGA C CXX )

find_package( Threads )

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -pthread")

# Check whether the user has selected a BUILD_TYPE
IF ("${CMAKE_BUILD_TYPE}" STREQUAL "")

    message(STATUS "Build type not explicitly set. Trying to guess...")
    get_filename_component(BINDIR ${PROJECT_BINARY_DIR} NAME)
    IF (${BINDIR} MATCHES "RELEASE")
        set(CMAKE_BUILD_TYPE "RELEASE")
        message(STATUS "Set to ${CMAKE_BUILD_TYPE}")
    ELSEIF(${BINDIR} MATCHES "DEBUG")
        set(CMAKE_BUILD_TYPE "DEBUG")
        message(STATUS "Set to ${CMAKE_BUILD_TYPE}")
    ELSE()
        message(WARNING "Unable to deduce build type. Use -DCMAKE_BUILD_TYPE=<RELEASE/DEBUG>")
    ENDIF(${BINDIR} MATCHES "RELEASE")

ELSE()
    message(STATUS "Build Type is ${CMAKE_BUILD_TYPE}")
ENDIF("${CMAKE_BUILD_TYPE}" STREQUAL "")

# Now set some compiler flags
IF( ${CMAKE_BUILD_TYPE} MATCHES "DEBUG" )
  IF( ${CMAKE_CXX_COMPILER_ID} MATCHES "GNU" )
    set( CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -O0 -Wall -pendatic \
-Wextra -dgdb -Wold-style-definition -Werror")
  ELSE()
    message( WARNING "Unable to determine Compiler ID: ${CMAKE_CXX_COMPILER_ID} ")
  ENDIF( ${CMAKE_CXX_COMPILER_ID} MATCHES "GNU" )

  message( STATUS "Debug flags for ${CMAKE_CXX_COMPILER_ID}: ${CMAKE_CXX_FLAGS_DEBUG} ")
ENDIF( ${CMAKE_BUILD_TYPE} MATCHES "DEBUG" )

IF( ${CMAKE_BUILD_TYPE} MATCHES "RELEASE" )
  IF( ${CMAKE_CXX_COMPILER_ID} MATCHES "GNU" )
    set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Ofast -fopenmp")
  ELSE()
    message( WARNING "Unable to determine Compiler ID: ${CMAKE_CXX_COMPILER_ID} ")
  ENDIF( ${CMAKE_CXX_COMPILER_ID} MATCHES "GNU" )

  message( STATUS "Release flags for ${CMAKE_CXX_COMPILER_ID}: ${CMAKE_CXX_FLAGS} ")
ENDIF( ${CMAKE_BUILD_TYPE} MATCHES "RELEASE" )

set( CMAKE_EXPORT_COMPILE_COMMANDS ON)

# ----------------------------------------------------------------------
find_package( LAPACK REQUIRED )
find_package( BLAS REQUIRED )

include(CheckIncludeFile)
include(CheckIncludeFileCXX)
include(CheckIncludeFiles)
include(ExternalProject)

include( external/dependencies.cmake)

add_subdirectory( modules )


add_subdirectory( test )
