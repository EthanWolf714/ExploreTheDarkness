cmake_minimum_required(VERSION 3.15)
project(game)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# compiler warnings
if(MSVC)
    add_compile_options(/W4)
else()
    add_compile_options(-Wall)
endif()


# Find raylib (system wide installation)
find_package(raylib 5.0 QUIET)

if(NOT raylib_FOUND)
    message(STATUS "raylib not found, attempting to use pkg-config")
    find_package(PkgConfig REQUIRED)
    pkg_check_modules(raylib REQUIRED raylib)
endif()


#collect all source files
file(GLOB_RECURSE SOURCES "src/*.cpp")

#create executable
add_executable(${PROJECT_NAME} ${SOURCES})

# Link raylib
target_link_libraries(${PROJECT_NAME} raylib)

# Platform-specific libraries
if(WIN32)
    target_link_libraries(${PROJECT_NAME} opengl32 gdi32 winmm)
endif()


# Platform-specific libraries
if(WIN32)
    target_link_libraries(${PROJECT_NAME} opengl32 gdi32 winmm)
endif()

# Build type settings
if(CMAKE_BUILD_TYPE STREQUAL "Release")
    if(WIN32)
        # Hide console window in release mode
        set_target_properties(${PROJECT_NAME} PROPERTIES WIN32_EXECUTABLE TRUE)
    endif()
    target_compile_options(${PROJECT_NAME} PRIVATE -O2)
elseif(CMAKE_BUILD_TYPE STREQUAL "Debug")
    target_compile_options(${PROJECT_NAME} PRIVATE -g)
endif()

# Output to build directory
set_target_properties(${PROJECT_NAME} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}
)