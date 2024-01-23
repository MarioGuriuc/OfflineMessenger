cmake_minimum_required(VERSION 3.26)
project(PROIECT_RETELE_SERVER)

set(CMAKE_CXX_STANDARD 23)

find_package(SQLite3 REQUIRED)

add_executable(PROIECT_RETELE_SERVER main.cpp
        handle_clients_logic.h
        queries_logic.h
        handle_clients_logic.cpp
        queries_logic.cpp)

target_link_libraries(PROIECT_RETELE_SERVER pthread SQLite::SQLite3)

