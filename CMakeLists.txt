# CMakeLists.txt
cmake_minimum_required(VERSION 3.29)
project(MPointers)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address -march=native -mtune=native")
set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

# Add GoogleTest and GoogleMock
set(GTEST_ROOT "$ENV{HOME}/local")
set(GMOCK_ROOT "$ENV{HOME}/local")
include_directories("${GTEST_ROOT}/include")
include_directories("${GMOCK_ROOT}/include")
include_directories("${CMAKE_SOURCE_DIR}")

# Link libraries
link_directories("${GTEST_ROOT}/lib")
link_directories("${GMOCK_ROOT}/lib")

# Main executable
add_executable(MPointers main.cpp MPointer.h MPointerGC.h MPointerGC.cpp DoublyLinkedList.h Sorters.h
        tests/MPointerTest.cpp
        main.cpp
        tests/MPointerGCTests.cpp
        tests/DLLTests.cpp
        tests/SortersTests.cpp
        )

# Test executable
add_executable(MPointerTests tests/MPointerTest.cpp MPointer.h MPointerGC.h MPointerGC.cpp DoublyLinkedList.h Sorters.h
        tests/MPointerTest.cpp
        tests/MPointerGCTests.cpp
        tests/DLLTests.cpp
        tests/SortersTests.cpp
        tests/main.cpp)

target_link_libraries(MPointers Threads::Threads
        gtest
        gmock
        gtest_main
        gmock_main)

target_link_libraries(MPointerTests Threads::Threads
        gtest
        gmock
        gtest_main
        gmock_main)

# Enable testing
enable_testing()

# Add test
add_test(
        NAME MPointerTests
        COMMAND MPointerTests
)
