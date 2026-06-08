# Heap Sort Report

## Chosen Data Structure and Algorithm

This project implements heap sort using an array-based binary max-heap built in place. The input array itself is treated as the heap storage, with child indices at `2*i + 1` and `2*i + 2`. The algorithm has two main phases:

1. **Heap construction**: convert the array into a valid max-heap by calling `siftDown` on every non-leaf node from the last parent down to the root.
2. **Sort-down extraction**: repeatedly swap the root of the heap with the last element in the current heap region, reduce the heap size by one, and then restore the heap property by sifting down the new root.

This is a textbook in-place heap sort implementation, so no extra heap data structure or STL internals are used.

## Complexity Analysis

Let `n` be the number of elements in the array.

### Heap building

- Each `siftDown` operation on a node takes `O(h)` time where `h` is the height of the subtree.
- The cost of heapifying from the last parent to the root is:
  - `O(n)` in total, because the number of nodes at depth `d` is `O(n / 2^d)` and each node costs `O(d)`.
- Therefore:
  - `T(n) = Θ(n)`
  - `O(n)` worst-case
  - `Ω(n)` best-case

### Sort-down extraction

- There are `n - 1` iterations.
- Each iteration swaps the maximum element to the back and performs `siftDown` on the root.
- `siftDown` costs `O(log n)` in the worst case.
- Total extraction cost is `O(n log n)` and `Θ(n log n)`.

### Combined heap sort

- Total runtime: `Θ(n log n)`.
- Worst-case: `O(n log n)`.
- Best-case: `Ω(n log n)` because extraction still requires heap repairs even on the best input.
- Space complexity: `Θ(1)` extra space beyond the input array, since the algorithm sorts in place.

## Empirical Timing

The benchmark compares the custom heap sort implementation against `std::sort` for the following input types:

- random data
- already sorted data
- reverse-sorted data

Measurements were collected for input sizes `1000`, `10000`, and `100000`. Each measurement was averaged over 5 runs to reduce timing variability.

### Benchmark results

| Size | Input Type | HeapSort (ms) | std::sort (ms) |
|------|------------|---------------|----------------|
| 1000 | random | 0.386 | 0.271 |
| 1000 | sorted | 0.383 | 0.150 |
| 1000 | reverse-sorted | 0.390 | 0.133 |
| 10000 | random | 3.877 | 2.403 |
| 10000 | sorted | 3.181 | 1.321 |
| 10000 | reverse-sorted | 3.140 | 1.088 |
| 100000 | random | 54.027 | 35.940 |
| 100000 | sorted | 35.720 | 16.391 |
| 100000 | reverse-sorted | 43.602 | 13.115 |

> Note: `std::sort` is faster on these inputs due to implementation optimizations and a smaller constant factor. Heap sort remains more consistent across input shapes, demonstrating the expected `Θ(n log n)` growth and in-place operation.

## Observations

- Heap sort does not benefit significantly from sorted or reverse-sorted input, as expected from its `Θ(n log n)` behavior.
- `std::sort` is much faster on the tested sizes due to a smaller constant factor and hybrid optimizations.
- The implementation uses no additional heap memory beyond the input array, satisfying the in-place requirement.

## Conclusion

This implementation provides a clean, from-scratch heap sort in C++ with a header/source separation, a command-line demo, a benchmark mode, and a comprehensive unit test file. The algorithm matches the theoretical complexity of `Θ(n log n)` and demonstrates predictable runtime across input patterns.
