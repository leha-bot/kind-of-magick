# kind-of-magick
This repository contains some ImageMagick/GraphicsMagick examples and sample build config with vcpkg/Conan.

## Getting started
###Windows
1. Make sure that you installed the Visual Studio (or Build Tools) with Windows SDK and C++ Development payload and [CMake](cmake.org).
2. (if you want to use vcpkg for getting deps and futher building) Install [vcpkg](github.com/Microsoft/vcpkg), add vcpkg.exe directory to PATH env variable and make VCPKG env variable with vcpkg directory as value.
3. Start Developer Command Prompt from root of cloned project, and type (assuming that vcpkg is available in your PATH and you have Visual Studio 2019/ 2019 Build Tools):

```bat
mkdir build
cd build
cmake .. -G "Visual Studio 16 2019 Win64" -DCMAKE_TOOLCHAIN_FILE="%VCPKG%\scripts\buildsystems\vcpkg.cmake"
cmake --build .
```
Done!

4. (If you want to use [Conan](https://conan.io) for getting deps and futher building) Install [Python](https://python.org) (Note: unless conan-io/conan#6347 is fixed, the recommended Python version is 3.7) and add it to your PATH.
5. Start Developer Command Prompt from root of cloned project and type (assuming that python is available in your PATH and you have Visual Studio 2019/ 2019 Build Tools):
```bat
pip install conan
mkdir build
cd build
conan remote add conan-center https://conan.bintray.com
conan install .. --build missing
cmake .. -G "Visual Studio 16 2019 Win64"
cmake --build .
```
Done!
