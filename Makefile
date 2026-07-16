# Makefile wrapper for CMake build system

.PHONY: all build clean run

all: build

build:
	cmake -B build
	cmake --build build

run: build
	./build/Hotel-Management-System

clean:
	rm -rf build
