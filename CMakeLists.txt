cmake_minimum_required (VERSION 2.8)
project (Paraballs)

set( Paraballs_VERSION_MAJOR 1 )
set( Paraballs_VERSION_MINOR 0 )

find_package(OpenMP)
if(OPENMP_FOUND)
    set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
    set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
else()
    message("OpenMP not found")
endif()

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set( Paraballs_SOURCES
     paraballs/MetaballsGenerator.cpp
     main.cpp )

add_executable(
    paraballs paraballs ${Paraballs_SOURCES} )

install( TARGETS paraballs DESTINATION bin )
