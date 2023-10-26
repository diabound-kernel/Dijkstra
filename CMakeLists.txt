cmake_minimum_required(VERSION 3.18)
project(Dijkstra)

set(CMAKE_CXX_STANDARD 20)

include(FetchContent)

FetchContent_Declare(
    range-v3
    GIT_REPOSITORY https://github.com/ericniebler/range-v3.git
    GIT_TAG master
)
FetchContent_MakeAvailable(range-v3)

add_executable(Dijkstra main.cpp graph/)
target_link_libraries(${PROJECT_NAME} range-v3)