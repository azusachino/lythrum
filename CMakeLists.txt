cmake_minimum_required(VERSION 3.10)

project(Lythrum)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# For Homebrew installations
set(ROCKSDB_ROOT_DIR "/opt/homebrew/Cellar/rocksdb/9.10.0/include")

find_package(RocksDB REQUIRED)

include_directories(${RocksDB_INCLUDE_DIRS})

file(GLOB SOURCES
    src/*.cpp
    src/utils/*.h
)

add_executable(Lythrum ${SOURCES})

target_link_libraries(Lythrum ${RocksDB_LIBRARIES})