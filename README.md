# EDM4hep-utils

This repository contains utility functionality that facilitates working with
[EDM4hep](https://github.com/key4hep/EDM4hep).

## Dependencies

Required:
 - [EDM4hep](https://github.com/key4hep/EDM4hep)
 
 
## Build and install
This project follows the key4hep guidelines and can be built with CMake:

``` sh
git clone https://github.com/key4h4p/EDM4hep-utils
cd EDM4hep-utils && mkdir build
cd build
cmake ..
make
```

The built library files will have to be put onto `LD_LIBRARY_PATH` for
downstream usage.

## Contributing

Contributions and bug reports are welcome! See our [contribution
guidelines](doc/contributing.md) if you want to contribute code to EDM4hep-utils
