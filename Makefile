SOURCES := $(wildcard src/*.cpp)

build:
	clang++ -o bin/txt8 $(SOURCES) -std=c++17

clean:
	rm -rf bin/txt8
