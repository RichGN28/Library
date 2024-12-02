# Library
This is a school project in which we dived in OOP, and I add a database to challenge myself


# How to compile
create a directory named "build", cd into it, and run "cmake .." in your terminal.
It should have create it some files to run

## MAC
Use the "make" command

## Windows
### Requirements
* git installed
* c++ compiler, Windows: WinGW, MacOS:make
* CMake(3.10 or later) to create the binarys to run the app
* C++11 or later
### Steps
1. Navigate to the folder where you want to store the project:
```
cd path\to\desired\directory
```
2. Clone the repository:
```
git clone https://github.com/RichGN28/Library
```
3. Navigate to the new folder
```
cd Library
```
4. make a new build directory to store the binarys
```
mdkir build
cd build
```
6. Run ```cmake``` to generate build files compatibles with windows
```
cmake .. -G "MinGW Makefiles"
```
7. run ``` mingw32-make``` to create the binary to run the code
