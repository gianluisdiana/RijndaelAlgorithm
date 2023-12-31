#
# Author: Gian Luis Bolivar Diana
# Date: November 7, 2022
# e-mail: gianluisbolivar1@gmail.com
#
# Makefile for the CESINF VIII Treasure Hunt.
#

#
# 'make'        build executable file 'main'
# 'make clean'  removes all .o and executable files
# 'make setup'  creates the necesary folders
#

# Cpp compiler to use
CXX := g++
# Compile-time flags
CXXFLAGS := -O3 -Wall -Wextra -Wshadow -std=c++2b -ggdb

# Executable name
EXEC := exec.out

# Define object files
OBJS := build/main.o build/functions.o build/rijndael.o build/input_error.o

# Default target
all: setup $(EXEC)

# Create the executable from the compiled objects
$(EXEC): $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o bin/$@

# Compile the classes implementation
build/%.o: lib/%.cc include/%.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Compile the main and the auxiliary functions
build/%.o: src/%.cc include/functions.h include/matrix.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

# PHONY targets (not associated with file creation)
.PHONY: clean setup

# Delete the compiled object and the excutable
clean:
	@for file in $(OBJS); do if [ -f "$$file" ]; then rm $$file; fi; done
	@if [ -f "./bin/$(EXEC)" ]; then rm ./bin/$(EXEC); fi

# Create the necesary folders to build the code
setup:
	@if [ ! -d "./bin" ]; then mkdir bin; fi
	@if [ ! -d "./build" ]; then mkdir build; fi