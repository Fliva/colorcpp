cmake_minimum_required(VERSION 2.6)
project(colorcpp)

# Enable debug symbols by default
if(CMAKE_BUILD_TYPE STREQUAL "")
  set(CMAKE_BUILD_TYPE Debug)
endif()

set(SOURCE_DIRECTORY ${PROJECT_SOURCE_DIR}/src)
set(COLORCPP_LIBRARY colorcpp)
set(COLORCPP_INCLUDE ${PROJECT_SOURCE_DIR}/include)

include_directories(${COLORCPP_INCLUDE})
add_library(${COLORCPP_LIBRARY} ${SOURCE_DIRECTORY}/color.cpp)
target_compile_features(${COLORCPP_LIBRARY} PRIVATE cxx_auto_type)


