# qupid

> Now, importing whole library of [python-qupid](https://github.com/Isaac-Kwon/qupid) to C++

**Qu**asi-Signal Generation Model for **Pi**xelized **D**etector

## Requirement

* ROOT (as visualization tool) [link](https://root.cern)
    * If you don't use QPGraphFactory, you don't need.
    * Automatic building rejection will be implemented ~~before dead~~.
* CMake version 3.2+

## How to build

1. Clone Repository

   ```bash
   git clone https://github.com/Isaac-Kwon/c-qupid.git
   ```

2. Make and enter the build directory

   ```bash
   mkdir build
   cd build
   ```

3. CMake

   ```bash
   cmake ..
   ```

4. Make

   ```bash
   make ..
   ```

## Note

* All *.cxx file in test directory will be built as executable.
  * Incompleted *.cxx file should be removed to suppress build error.
