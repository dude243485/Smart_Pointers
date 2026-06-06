cmake_minimum_required(VERSION 3.15)
project(SmartPointerLibrary VERSION 1.0.0 LANGUAGES CXX)

#Enforce C++17 standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_library(smart_pointers INTERFACE)

#expose the include directory to consumers of the library
target_include_directories(smart_pointers INTERFACE 
$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
$<INSTALL_INTERFACE:include>)

#set executable target
add_executable(memory_test tests/main.cpp)

#link our header-only library to the test executable
target_link_libraries(memory_test PRIVATE smart_pointers)

#strict warning flags and AddressSanitizer for safety
if (MSVC)
    target_compile_options(memory_test PRIVATE /W4 /WX)
else()
    target_compile_options(memory_test PRIVATE -Wall -Wextra -Wpedantic -Werror -fsanitize=address -g)
    terget_link_options(memory_test PRIVATE -fsanitize=address)
endif()