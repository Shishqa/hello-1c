# Hello, 1C

## The task


## Prerequisites

- Linux distribution 
  (Tested on Arch Linux 5.10.25-1-lts. Probably, every Linux distro would be good)
- Xlib
- OpenGL
- GLEW
- C++ compiler (gcc, clang, ...)
- CMake

```bash
# On Arch
sudo pacman -S gcc cmake glew glu libx11

# Ubuntu:
sudo apt-get install gcc cmake glew glu libx11
```

## Building

```bash
mkdir build
cd build
cmake ..
cmake --build .
```

## Running

```bash
cd <repo-root>
./bin/hello-jetbrains
```

