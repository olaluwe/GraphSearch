# # Makefile for C++ project

# # Compiler settings -
# CXX = g++
# CXXFLAGS = -Wall -Wextra -std=c++17 -Iinclude
# LDFLAGS =

# # Put your source files here (use wildcard to include all .cpp files)
# SOURCES = $(wildcard src/*.cpp)

# # Ensure the build directory exists
# $(shell mkdir -p build)

# # Object files will be generated from .cpp source files
# OBJECTS = $(SOURCES:src/%.cpp=build/%.o)

# # Name of the executable to be created
# TARGET = bin/app

# # Ensure the bin directory exists
# $(shell mkdir -p bin)

# # Rule to create the executable
# $(TARGET): $(OBJECTS)
# 	$(CXX) $(OBJECTS) -o $@ $(LDFLAGS)

# # Rule to create object files
# build/%.o: src/%.cpp
# 	$(CXX) $(CXXFLAGS) -c $< -o $@

# # Rule to clean files created during compilation
# clean:
# 	rm -f $(OBJECTS) $(TARGET)
# 	rm -rf bin # This line is optional and will remove the bin directory entirely on clean

# .PHONY: clean

# Compiler
CC = g++

# Compiler flags
CFLAGS = -Wall -Wextra -Iinclude
LDFLAGS = 

# # Ensure the build directory exists
$(shell mkdir -p build)

# # Ensure the bin directory exists
$(shell mkdir -p bin)

# Directories
SRCDIR = src
INCDIR = include
BUILDDIR = build
BINDIR = bin

# Files
SRCS = $(wildcard $(SRCDIR)/*.cpp)
OBJS = $(patsubst $(SRCDIR)/%.cpp,$(BUILDDIR)/%.o,$(SRCS))
TARGET = $(BINDIR)/GraphSearch

# Targets
all: directories $(TARGET)

directories:
	mkdir -p $(BUILDDIR) $(BINDIR)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^ $(LDLIBS)

$(BUILDDIR)/%.o: $(SRCDIR)/%.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(BUILDDIR) $(BINDIR)
