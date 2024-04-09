# # Makefile for C++ project
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
