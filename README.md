# Author: Abiodun Olaluwe

# Graph Search

This project implements Depth and Breadth First, Uniform Cost, and A* Searches in C++.

## Description

The directory structure and content after compiling and linking is shown below:

```
├── bin
│   └── GraphSearch
├── build
│   ├── AStar.o
│   ├── DfsBfs.o
│   ├── main.o
│   ├── Misc.o
│   └── UniformCost.o
├── include
│   ├── AStar.h
│   ├── Constants.h
│   ├── DfsBfs.h
│   ├── Include.h
│   ├── Misc.h
│   └── UniformCost.h
├── Makefile
├── README.md
└── src
    ├── AStar.cpp
    ├── DfsBfs.cpp
    ├── main.cpp
    ├── Misc.cpp
    └── UniformCost.cpp
```

The file names of the header and corresponding `.cpp` files are descriptive of their functions.

## Getting Started

1. Install a functional IDE on preferably a Linux machine.
2. Install basic development tools (e.g., `sudo apt install build-essential`).
3. Install Git, GH, and Tree (e.g., `sudo apt install git gh tree`).

### Dependencies

Requires:
- >=C++17 compliant compiler or newer
- Make
- IDE (e.g., VSCode)

### Installing

Follow these steps to install and run the project:

```bash```
```
git clone https://github.com/olaluwe/GraphSearch.git
cd GraphSearch
make
./bin/GraphSearch
```

