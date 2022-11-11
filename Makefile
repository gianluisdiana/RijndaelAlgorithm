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

# Define the Cpp compiler to use
CXX          := g++
# Define any compile-time flags
CXX_FLAGS    := -O0 -Wall -Wextra -std=c++17 -ggdb

# Define object files
OBJ := build/main.o build/functions.o build/rijndael.o

# Compile the main and the auxiliary functions
build/%.o: lib/%.cc
	$(CXX) $(CXX_FLAGS) -c $< -o $@

# Compile the classes implementation
build/%.o: src/%.cc
	$(CXX) $(CXX_FLAGS) -c $< -o $@

# Create the executable from the compiled objects
exec.out: $(OBJ)
	$(CXX) $(CXX_FLAGS) $(OBJ) -o bin/exec.out

# Delete the compiled object and the excutable
clean:
	clear
	rm ./build/*.o ./bin/exec.out

# Create the necesary folders to build the code
setup:
	mkdir bin build