cmake_minimum_required(VERSION 3.20)
project(neoengine VERSION 0.1
                  DESCRIPTION "A physics engine I created after high school physics"
                  LANGUAGES CXX)
set (CMAKE_CXX_STANDARD 20)

# Require out-of-source builds
file(TO_CMAKE_PATH "${PROJECT_BINARY_DIR}/CMakeLists.txt" LOC_PATH)
if(EXISTS "${LOC_PATH}")
    message(FATAL_ERROR "You cannot build in a source directory (or any directory with a CMakeLists.txt file). Please make a build subdirectory. Feel free to remove CMakeCache.txt and CMakeFiles.")
endif()

add_subdirectory(vendor)
add_subdirectory(src)