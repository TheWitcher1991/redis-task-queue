cmake_minimum_required(VERSION 3.10)
project(RedisTaskQueue)

include_directories(${PROJECT_SOURCE_DIR}/include)

set(CMAKE_CXX_STANDARD 17)

find_package(PkgConfig REQUIRED)
pkg_search_module(HIREDIS REQUIRED hiredis)
include_directories(${HIREDIS_INCLUDE_DIRS})
target_link_libraries(TaskQueueExample ${HIREDIS_LIBRARIES})