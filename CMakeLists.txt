if (CMAKE_BUILD_TYPE STREQUAL "")
    # Build type is not set eg. command was "cmake .."
    message(STATUS "  Diag: Build type was unspecified, set to Release")
    set(CMAKE_BUILD_TYPE Release)
else ()
    message(STATUS "  Diag: Build type specified as '${CMAKE_BUILD_TYPE}'")
endif ()

if (${CMAKE_BUILD_TYPE} STREQUAL Debug)
    set_directory_properties(PROPERTIES COMPILE_DEFINITIONS "_DEBUG")
else ()
    set_directory_properties(PROPERTIES COMPILE_DEFINITIONS "NDEBUG")
endif ()

cmake_minimum_required(VERSION 3.1.0)

project(
    mediacenter
    VERSION 0.0.0
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_DEBUG_FLAGS ON)
set(CMAKE_CXX_FLAGS "-Wall")

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_AUTOUIC_SEARCH_PATHS ${CMAKE_CURRENT_SOURCE_DIR}/resources)

if (CMAKE_VERSION VERSION_LESS "3.7.0")
    set(CMAKE_INCLUDE_CURRENT_DIR ON)
endif()

find_package(
    Qt5
    COMPONENTS
    Core
    Widgets
    WebKitWidgets
)


add_subdirectory(src)

