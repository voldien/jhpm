# jhpm #
------
jhpm ( Java hpm) is a wrapper library of the hpm library for using it in the Java languages.

The project consists of declared java classes and the JNI code for implementation the mapping between the c code and the java methods.

# Motivation #
----
The project was created in order create Java interface library for utilizing the hpm library. Where the hpm ( high performance matrices) library uses the most approiated SIMD extension available on the system, in order to increase the performance per math operation. See more details at [hpm](https://github.com/voldien/hpm).

# Installation #
----
The project uses the *CMake* in order add compatibility for cross platform make files.
## Linux ##
The following commad covers how to compile and install the jhpm library on Linux throught the command line.
```
cmake .
make
make install
```

# Contributing #

Please read the [CONTRIBUTING](CONTRIBUTING.md) for more details of how you can contriubute.

## License ##

This project is licensed under the GPL+3 License - see the [LICENSE](LICENSE) file for details.

