cmake_minimum_required(VERSION 3.18) # Required for file(ARCHIVE_CREATE ...)
project(AsyncTiny VERSION 1.0.0 LANGUAGES CXX)

# Set C++ standard to C++11
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Define the library target (static by default, can be changed to SHARED)
set(LIBRARY_NAME ${PROJECT_NAME})
add_library(${LIBRARY_NAME} STATIC)

# Collect all source files in src and its subdirectories
file(GLOB_RECURSE SOURCES "src/*.cpp")

# Add source files to the library target
target_sources(${LIBRARY_NAME} PRIVATE ${SOURCES})

# Specify include directories for the library
# The src folder is marked PUBLIC so consumers also include it
target_include_directories(${LIBRARY_NAME}
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>
        $<INSTALL_INTERFACE:include>
)

# Install the library
install(TARGETS ${LIBRARY_NAME}
    EXPORT ${LIBRARY_NAME}Targets
    ARCHIVE DESTINATION lib
    LIBRARY DESTINATION lib
    RUNTIME DESTINATION bin
)

# Install header files to the include directory, preserving src hierarchy
install(DIRECTORY src/
    DESTINATION include
    FILES_MATCHING PATTERN "*.hpp" PATTERN "*.h" PATTERN "*.inc"
)

# Generate and install the export file for find_package
install(EXPORT ${LIBRARY_NAME}Targets
    FILE ${LIBRARY_NAME}Targets.cmake
    DESTINATION lib/cmake/${LIBRARY_NAME}
)

# Create a CMake config file for the library
include(CMakePackageConfigHelpers)
write_basic_package_version_file(
    "${CMAKE_CURRENT_BINARY_DIR}/${LIBRARY_NAME}ConfigVersion.cmake"
    VERSION ${PROJECT_VERSION}
    COMPATIBILITY SameMajorVersion
)

configure_package_config_file(
    "${CMAKE_CURRENT_SOURCE_DIR}/cmake/${LIBRARY_NAME}Config.cmake.in"
    "${CMAKE_CURRENT_BINARY_DIR}/${LIBRARY_NAME}Config.cmake"
    INSTALL_DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/${LIBRARY_NAME}
    PATH_VARS ${CMAKE_INSTALL_INCLUDEDIR}
)
# Install the config and version files
install(FILES
    "${CMAKE_CURRENT_BINARY_DIR}/${LIBRARY_NAME}Config.cmake"
    "${CMAKE_CURRENT_BINARY_DIR}/${LIBRARY_NAME}ConfigVersion.cmake"
    DESTINATION lib/cmake/${LIBRARY_NAME}
)

# Arduino build: Create a zip file for Arduino library distribution
option(BUILD_ARDUINO_ZIP "Build Arduino library zip file" OFF)
if(BUILD_ARDUINO_ZIP)
    # Define staging directory for Arduino zip contents
    set(ARDUINO_STAGING_DIR "${CMAKE_CURRENT_BINARY_DIR}/arduino_staging")

    file(COPY "${CMAKE_CURRENT_SOURCE_DIR}/examples/arduino/" DESTINATION "${ARDUINO_STAGING_DIR}/${LIBRARY_NAME}/examples/")

    file(COPY "${CMAKE_CURRENT_SOURCE_DIR}/src/" DESTINATION "${ARDUINO_STAGING_DIR}/${LIBRARY_NAME}/src/")

    # Generate library.properties
    configure_file(
        "${CMAKE_CURRENT_SOURCE_DIR}/cmake/library.properties.in"
        "${ARDUINO_STAGING_DIR}/${LIBRARY_NAME}/library.properties"
        @ONLY
    )

    file(ARCHIVE_CREATE
        OUTPUT "${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}.zip"
        PATHS "${LIBRARY_NAME}"
        WORKING_DIRECTORY "${ARDUINO_STAGING_DIR}"
        FORMAT zip
    )

    # Custom target to ensure the zip is built
    add_custom_target(arduino_zip
        DEPENDS "${CMAKE_CURRENT_BINARY_DIR}/${LIBRARY_NAME}.zip"
        COMMENT "Creating Arduino library zip file: ${LIBRARY_NAME}.zip"
    )
endif()