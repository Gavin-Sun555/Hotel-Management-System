cmake_minimum_required(VERSION 3.10)
project(Hotel-Management-System C)
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -pedantic -Werror")

add_executable(Hotel-Management-System hotel-main.c hotel-ll.c hotel-ll.h hotel-mt.c hotel-mt.h hotel-db.c hotel-db.h)