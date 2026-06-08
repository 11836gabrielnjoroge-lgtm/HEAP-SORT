#include "HeapSort.h"

#include <utility>

namespace heap_sort {

namespace {

void siftDown(std::vector<int>& values, int start, int end) {
    int root = start;

    while (true) {
        int leftChild = 2 * root + 1;
        if (leftChild >= end) {
            break;
        }

        int swapIndex = root;
        if (values[swapIndex] < values[leftChild]) {
            swapIndex = leftChild;
        }

        int rightChild = leftChild + 1;
        if (rightChild < end && values[swapIndex] < values[rightChild]) {
            swapIndex = rightChild;
        }

        if (swapIndex == root) {
            return;
        }

        std::swap(values[root], values[swapIndex]);
        root = swapIndex;
    }
}

void buildMaxHeap(std::vector<int>& values) {
    int count = static_cast<int>(values.size());
    for (int start = (count / 2) - 1; start >= 0; --start) {
        siftDown(values, start, count);
    }
}

} // namespace

void HeapSort::sort(std::vector<int>& values) {
    if (values.size() < 2) {
        return;
    }

    buildMaxHeap(values);

    for (int end = static_cast<int>(values.size()) - 1; end > 0; --end) {
        std::swap(values[0], values[end]);
        siftDown(values, 0, end);
    }
}

} // namespace heap_sort
