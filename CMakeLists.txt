# MINIMUN VERSION OF CMAKE REQUIRED
cmake_minimum_required(VERSION 3.10)

# PROJECT
project(Library)

# C++ STANDARD
set(CMAKE_CXX_STANDARD 11)

# Add the include directory (where your .h files are located)
include_directories(${PROJECT_SOURCE_DIR}/include)

# Add source files (e.g., main.cpp, other_file.cpp)
set(SOURCE_FILES 
    src/app.cpp
    src/classes.cpp
    src/helpers.cpp
)

# Define the executable and link source files to it
add_executable(library ${SOURCE_FILES})

# If you need libraries, you can link them here
# target_link_libraries(myapp mylib)
