# Introduction

## 1. Original mwrap (on Unix systems)

mwrap-0.33 (http://www.cims.nyu.edu/~dbindel/mwrap/)

MWrap is an interface generation system in the spirit of SWIG or matwrap. From
a set of augmented MATLAB script files, MWrap will generate a MEX gateway to
desired C/C++ function calls and MATLAB function files to access that gateway.
The details of converting to and from MATLAB's data structures, and of
allocating and freeing temporary storage, are hidden from the user.

To compile, edit make.inc and then run make. The output will be a standalone
executable (mwrap) in the main directory.

The user's guide (mwrap.pdf) describes MWrap in detail; you can also look at
the example subdirectories and the testing subdirectory to get some idea of
how MWrap is used.

---

==This project port original, Unix-specified mwrap to win10, with CMake + Visual Studio 2019 support.==

# Build steps on windows

1. `mkdir build`
2. `cmake .. -DCMAKE_BUILD_TYPE=Debug`, get a `mwrap.sln`
3. you can build `mwrap.sln` in `Visual Studio`;-)
4. get `mwrap.exe` and enjoy!
