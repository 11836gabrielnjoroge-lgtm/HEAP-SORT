#include "HeapSort.h"

#include <algorithm>
#include <cassert>
#include <iostream>
#include <random>
#include <vector>

int main() {
    // Normal cases
    {
        std::vector<int> values = {4, 1, 7, 3, 9, 2};
        heap_sort::HeapSort::sort(values);
        assert(std::is_sorted(values.begin(), values.end()));
    }

    // Edge cases
    {
        std::vector<int> empty;
        heap_sort::HeapSort::sort(empty);
        assert(empty.empty());
    }

    {
        std::vector<int> single = {42};
        heap_sort::HeapSort::sort(single);
        assert(single.size() == 1 && single[0] == 42);
    }

    {
        std::vector<int> alreadySorted = {1, 2, 3, 4, 5};
        heap_sort::HeapSort::sort(alreadySorted);
        assert(std::is_sorted(alreadySorted.begin(), alreadySorted.end()));
    }

    {
        std::vector<int> reversed = {5, 4, 3, 2, 1};
        heap_sort::HeapSort::sort(reversed);
        assert(std::is_sorted(reversed.begin(), reversed.end()));
    }

    {
        std::vector<int> duplicates = {7, 1, 7, 3, 1, 7};
        heap_sort::HeapSort::sort(duplicates);
        assert(std::is_sorted(duplicates.begin(), duplicates.end()));
    }

    // Stress test
    {
        const int size = 100000;
        std::mt19937 generator(12345);
        std::uniform_int_distribution<int> distribution(-1000000, 1000000);
        std::vector<int> values;
        values.reserve(size);

        for (int i = 0; i < size; ++i) {
            values.push_back(distribution(generator));
        }

        std::vector<int> expected = values;
        std::sort(expected.begin(), expected.end());

        heap_sort::HeapSort::sort(values);
        assert(values == expected);
    }

    std::cout << "All heap sort tests passed." << std::endl;
    return 0;
}
