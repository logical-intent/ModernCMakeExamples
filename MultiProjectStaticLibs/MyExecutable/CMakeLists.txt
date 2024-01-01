# CMakeList.txt : CMake project for MyExecutable, include source and define
# project specific logic here.
#



# Define this project's target (MyExecutable) as an executable (not a library) and specify its source files
add_executable (MyExecutable "src/MyExecutable.cpp" "src/MyExecutable.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET MyExecutable PROPERTY CXX_STANDARD 20)
endif()

# State that this target (MyExecutable) depends on other targets (HelloLib and StringTransformerLib)
target_link_libraries(MyExecutable PRIVATE HelloLib)
target_link_libraries(MyExecutable PRIVATE StringTransformerLib)

# TODO: Add tests and install targets if needed.

