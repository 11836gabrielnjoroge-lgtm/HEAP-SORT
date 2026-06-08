cmake_minimum_required(VERSION 3.10)
project(HeapSortProject LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include_directories(${PROJECT_SOURCE_DIR}/include)

add_library(heap_sort STATIC src/HeapSort.cpp)

add_executable(heap_sort_demo src/main.cpp)
target_link_libraries(heap_sort_demo PRIVATE heap_sort)

add_executable(heap_sort_test tests/heap_sort_test.cpp)
target_link_libraries(heap_sort_test PRIVATE heap_sort)
