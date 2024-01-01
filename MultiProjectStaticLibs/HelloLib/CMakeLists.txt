# CMakeList.txt : CMake project for HelloLib, include source and define
# project specific logic here.
#

# Define this project's target (HelloLib) as a library (not executable) and specify its source files
add_library (HelloLib "src/Hello.cpp" "include/HelloLib/Hello.h")

# State that this target's include directories are just the one called "include" (./include/ relative 
# to this CMakeLists.txt).  This directory will be added to the preprocessor include paths for this 
# project, and for any projects that are dependents of this project via target_link_libraries(). 
target_include_directories(HelloLib PUBLIC include)

# State that this target (HelloLib) depends on another target (StringTransformerLib). 
# NOTE: Because we declare the dependency as PRIVATE, dependents of HelloLib won't have 
#       StringTransformerLib's include directories in their preprocessor include paths, but
#       they will be linked to StringTransformerLib due to the transitive dependency.  
#       (If we had declared the dependency as PUBLIC, dependents of HelloLib would also get
#       StringTransformerLib's include directories in their preprocessor include paths.)
target_link_libraries(HelloLib PRIVATE StringTransformerLib)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET HelloLib PROPERTY CXX_STANDARD 20)
endif()
