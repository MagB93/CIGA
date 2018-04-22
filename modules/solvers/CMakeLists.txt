cmake_minimum_required(VERSION 3.2)
project( CIGA )

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

add_subdirectory( base )
add_subdirectory( nurbs )
add_subdirectory( math )
add_subdirectory( solvers )

