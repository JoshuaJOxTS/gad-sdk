# OxTS Generic Aiding SDK

For more information on OxTS Generic Aiding Solutions, see [here](https://www.oxts.com/what-is-generic-aiding/)

Note: Clone this repository with the --recursive option to ensure pybind11 is available. 

This project contains the OxTS GAD SDK, written in C++. This SDK is designed to allow users to encode aiding data to GAD packets and send them to an OxTS INS for use in the navigation solution. It also contains NCom decoder functionality, for those who wish to receive data from the unit.

Find the full code documentation for this project at: [https://oxfordtechnicalsolutions.github.io/index.html](https://oxfordtechnicalsolutions.github.io/index.html)

## Requirements

- CMake >3.1 (Last version tested 3.23)
- Boost 1.71 (requirement can be disabled, though this will remove UDP functionality)
- Generic Aiding Feature Codes.
- Ethernet connection to an OxTS INS, for real-time aiding.
- C/C++ Compiler (Easiest option is to install Visual Studio Professional 2019 (not 2022 - boost won't install) on Windows, Linux GCC)

### Installing requirements on Linux

```
sudo apt-get install cmake
sudo apt-get install libboost-all-dev
```

### Installing requirements on Windows 

- Download and install [CMake](https://cmake.org/download/) (the latest msi installer should be sufficient)
- Download [Boost](https://www.boost.org/users/download/)
  - Extract the files to a sensible location such as C:\Libs. Note you do not need to create an extra containing folder. The full path to the boost libraries should resemble C:\Libs\boost_1_77_0.
  - In a command prompt navigate to the boost directory and run ``` bootstrap.bat ``` - Then run ```b2.exe link=shared``` to install boost.
  - Edit your environment variables and add the variable ```BOOST_ROOT``` with value equal to the path to your boost library. In this example the value would be ```C:\Libs\boost_1_77_0```

## Building from source

Users can build the SDK from source, using the following instructions:

1. Clone the repository onto the PC.

   ```git clone https://github.com/OxfordTechnicalSolutions/gad-sdk.git --recursive```
2. Navigate to the root directory of the repository
3. (Optional) Edit the CMakeLists.txt file in the root of the repository to 
   configure options, such as enabling building of examples and documentation.
4. Execute the following commands:

### Linux
```
mkdir _build && cd _build 
cmake ..
cmake --build . --target install
```
This will build the SDK and install it to your machine. Your machine may report an error from the INSTALL that permission to copy a file has been denied. In this case run the last command again, but add `sudo` to the start. This should provide the correct access rights to install files to the correct location. 

### Windows
```
mkdir _build
cd _build
cmake ..
cmake --build . --target install
```
This will build the SDK and install it on your machine. You may need to run CMD or Powershell as an adminitrator if the SDK fails to install.

Use the same compiler to build boost and to build the GAD SDK or the boost libraries will not be found.

Once this is complete, other CMake projects on the machine can link to the libraries using:

```
find_package(oxts-sdk-gal-cpp REQUIRED)
find_package(Boost COMPONENTS system thread regex)

target_link_libraries(${PROJECT_NAME} 
    PUBLIC
        oxts-sdk-gal-cpp
)
```
in their CMakeLists.txt. 
Header files can then be included in code files using 
`#include "oxts/<oxts-sdk-module>/<filename>.hpp".

### Build options

The CMakeLists.txt file in the root of the repository contains some options for building the SDK.

| Option | Description | Default |
|-------------|---------------|----|
|OXTS_SDK_BUILD_EXAMPLES|Enable examples targets.| ON |
|OXTS_SDK_DISABLE_BOOST|Use Boost library when building. Note that not using boost will limit UDP functionality, which will need to be replaced by the user in order to send GAD to an INS.| OFF |
<!-- |OXTS_SDK_BUILD_DOCS|Build SDK documentation.| OFF | -->

### Building the docs

The documentation for this project can be found [here](https://oxfordtechnicalsolutions.github.io/index.html).

It is not necessary to build the documentation, however for reference, this can be generated using the following tools: Doxygen, Breathe, and Sphinx. 

It is only buildable in Linux currently.

1. Install requirements (python 3.7 also required):
```
  pip install -U sphinx
  pip3 install sphinx-rtd-theme
  pip3 install sphinx-sitemap
  pip3 install breathe

```
2. Navigate to the `docs_sphinx` directory and run the command:
```
  sphinx-build -b html . public
```
## Running

See the extended documentation for using the SDK.  If built using Visual Studio all code with examples and unit tests are avaialble in the solution (oxts-sdk.sln) in the build folder.  This automatically links to the source files in each specific folder in the root directory.

## Python GAD SDK (Windows and Linux)

Note: As of PIP 21.3 pip creates build files locally in a folder called build instead of a temporary folder. If the boost install directory changes or the path isn't set properly then the build folder should be manually deleted before trying to install again. Likewise if modifying the code and installing again then the build folder should be deleted.  

The C++ SDK has been wrapped in Python using PyBind11. The interface for the Python code largely matches that of the C++ code, though class accessors have been replaced with Python properties.

The Python SDK is not yet  documented, though its binding to the C++ can be found in `oxts-sdk-py/gal-py-bindings.cpp`. There is also an example in `examples/python/my-first-gad.py`.

To install the package, use `pip install ./gad-sdk-master` from the directory above the repository folder. After that, it can be imported using `import oxts_sdk`.
