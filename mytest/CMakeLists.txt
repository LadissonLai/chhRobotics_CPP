cmake_minimum_required(VERSION 3.0)
project(mytest)

set(Python3_ROOT_DIR /home/u20/anaconda3/envs/rda/bin)
find_package(Python3 COMPONENTS Interpreter Development REQUIRED)
if(Python3_Interpreter_FOUND)
    message(STATUS "111 Found Python3: ${Python3_EXECUTABLE}")
else()
    message(STATUS "Python3 not found")
endif()

set(Python3_NumPy_ROOT ${Python3_ROOT_DIR})
find_package(Python3 COMPONENTS NumPy REQUIRED)
if(Python3_NumPy_FOUND)
    message(STATUS "222 Found NumPy: ${Python3_NumPy_INCLUDE_DIRS}")
else()
    message(STATUS "NumPy not found")
endif()

add_executable(main cpp_call_matplotlib.cpp)
target_link_libraries(main PRIVATE Python3::Python Python3::NumPy)


