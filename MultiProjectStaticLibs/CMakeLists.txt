# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.8)

project ("CMakeSolution")

# Include sub-projects.  
# Note:  These do *NOT* have to be included in any kind of dependency order. 
add_subdirectory ("MyExecutable")
add_subdirectory ("StringTransformerLib")
add_subdirectory ("HelloLib")
