# CMakeList.txt : CMake project for StringTransformerLib, include source and define
# project specific logic here.
#

# Define this project's target (StringTransformerLib) as a library (not executable) and specify its source files
add_library (StringTransformerLib "src/StringTransformer.cpp" "include/StringTransformerLib/StringTransformer.h")

# State that this target's include directories are just the one called "include" (./include/ relative 
# to this CMakeLists.txt).  This directory will be added to the preprocessor include paths for this 
# project, and for any projects that are dependents of this project via target_link_libraries(). 
target_include_directories(StringTransformerLib PUBLIC include)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET StringTransformerLib PROPERTY CXX_STANDARD 20)
endif()
