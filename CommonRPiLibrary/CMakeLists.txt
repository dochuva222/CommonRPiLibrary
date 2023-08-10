cmake_minimum_required (VERSION 3.8)

project (CommonRPiLibrary VERSION 1.0.1)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_COMPILER gcc)

# Add your source files here
set(SOURCES
    src/CommonRPiLibrary.c
    src/SPI.c
    src/USB.c
    # Add more source files as needed
)

# Add header files directory
include_directories(include)

# Create a shared library from the sources
add_library(${PROJECT_NAME} SHARED ${SOURCES})

# Set library version
set_target_properties(${PROJECT_NAME} PROPERTIES VERSION ${PROJECT_VERSION})

# Install library and header files
install(TARGETS ${PROJECT_NAME}
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
)
install(DIRECTORY include/ DESTINATION include/${PROJECT_NAME})

# Print information
message(STATUS "Project Name: ${PROJECT_NAME}")
message(STATUS "Project Version: ${PROJECT_VERSION}")