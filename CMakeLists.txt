cmake_minimum_required(VERSION 3.22)

project(homework1 CXX)
set(TARGET ${CMAKE_PROJECT_NAME})

include(GNUInstallDirs)

find_package(Threads)

set (CMAKE_POSITION_INDEPENDENT_CODE ON)
if (NOT CMAKE_BUILD_TYPE)
    set (CMAKE_BUILD_TYPE RelWithDebInfo)
endif (NOT CMAKE_BUILD_TYPE)

include(GNUInstallDirs)
include(CMakePrintHelpers)

add_library(${TARGET} STATIC src/QuadraticEquation.cpp)
add_library(otus::homework1 ALIAS ${TARGET})

target_include_directories(${TARGET} PUBLIC "$<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include>"
        "$<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>")

target_link_libraries(
    ${TARGET}
    PUBLIC
)

set_target_properties(
    ${TARGET}
    PROPERTIES
    CXX_STANDARD 20
    CXX_EXTENSIONS OFF
)

include(CTest)
add_subdirectory(3rdparty/gtest)
enable_testing()
add_subdirectory(tests)


