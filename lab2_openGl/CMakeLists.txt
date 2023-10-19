cmake_minimum_required(VERSION 3.0)

project(lab2_2)

# Locate necessary packages
find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)

# Add executable
add_executable(lab2_2 lab2_2.cpp)

# Link necessary libraries
target_link_libraries(lab2_2 ${OPENGL_LIBRARIES} ${GLUT_LIBRARIES})

# Enable debugging
set(CMAKE_BUILD_TYPE Debug)

# Set additional compiler flags for debugging
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g")

# Set the path to the debugged executable
set_target_properties(lab2_2 PROPERTIES
    COMPILE_FLAGS "-g"
    RUNTIME_OUTPUT_DIRECTORY_DEBUG "${CMAKE_BINARY_DIR}/debug"
)
