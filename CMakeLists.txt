cmake_minimum_required(VERSION 3.10)

# Set the project name and version
project(libutils VERSION 1.1.0 LANGUAGES C)

# Set the C standard
set(CMAKE_C_STANDARD 17)

# Specify the source files
file(GLOB SOURCES "src/*.c")

# Include directories
include_directories(include)

# Create the static library
add_library(customutils STATIC ${SOURCES})

# Set the output directory for the library
set_target_properties(customutils PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

# Installation rules for the library
install(TARGETS customutils
    ARCHIVE DESTINATION lib
    LIBRARY DESTINATION lib
    RUNTIME DESTINATION bin)

# Install headers
install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/include/ DESTINATION include)

# Create an executable for testing (not installed)
add_executable(main src/main.c)

# Set the output directory for the executable
set_target_properties(main PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Link the static library to the executable
target_link_libraries(main customutils)

# Create and install a CMake package configuration file
include(CMakePackageConfigHelpers)
configure_package_config_file(
    ${CMAKE_CURRENT_SOURCE_DIR}/customutilsConfig.cmake.in
    ${CMAKE_CURRENT_BINARY_DIR}/customutilsConfig.cmake
    INSTALL_DESTINATION lib/cmake/customutils
)

# Install the generated configuration file
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/customutilsConfig.cmake
    DESTINATION lib/cmake/customutils)
