# HEAP-SORT

This repository contains a clean C++ implementation of heap sort.

## Project contents

- `include/HeapSort.h` — heap sort public interface
- `src/HeapSort.cpp` — in-place heap sort implementation from scratch
- `src/main.cpp` — command-line demo and benchmark application
- `tests/heap_sort_test.cpp` — unit test file using `assert`
- `CMakeLists.txt` — build script
- `REPORT.md` — algorithm analysis, complexity derivation, and benchmark results

## Build

```bash
mkdir -p build
cd build
cmake ..
cmake --build .
```

## Run demo

```bash
./heap_sort_demo --demo
```

## Run benchmark

```bash
./heap_sort_demo --benchmark
```

## Run tests

```bash
./heap_sort_test
```
