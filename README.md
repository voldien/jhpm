# jhpm #
[![Actions Build Status](https://github.com/voldien/jhpm/workflows/jhpm/badge.svg?branch=master)](https://github.com/voldien/jhpm/actions)
[![License: GPL v3](https://img.shields.io/badge/License-GPLv3-blue.svg)](https://www.gnu.org/licenses/gpl-3.0)
[![GitHub release](https://img.shields.io/github/release/voldien/jhpm.svg)](https://github.com/voldien/jhpm/releases)

jhpm ( Java hpm) is a wrapper library of the hpm library for using it in the Java languages.

The project consists of declared java classes and the JNI code for implementing the mapping between the c code and the java methods.

# Motivation #

The project was created in order to create a Java interface library for utilizing the hpm library. Where the hpm (high-performance matrices) library uses the most appropriated SIMD extension available on the system, in order to increase the performance per math operation. See more details at [hpm](https://github.com/voldien/hpm).

# Installation #

The project uses the *CMake* in order to add compatibility for cross-platform make files.
## Linux ##
The following command covers how to compile and install the npm library on Linux through the command line.
```
mkdir build
cd build
cmake ..
make
```

## Dependencies ##
The library depends on the hpm library and the java development kit.
```bash
sudo apt install default-jdk
```

# License #
This project is licensed under the GPL+3 License - see the [LICENSE](LICENSE) file for details.

