#include "HeapSort.h"

#include <algorithm>
#include <chrono>
#include <iostream>
#include <random>
#include <string>
#include <vector>

namespace {

using Clock = std::chrono::high_resolution_clock;
using Duration = std::chrono::duration<double, std::milli>;

std::vector<int> generateRandomVector(int size, int minValue = -100000, int maxValue = 100000) {
    std::mt19937 generator(static_cast<unsigned int>(Clock::now().time_since_epoch().count()));
    std::uniform_int_distribution<int> distribution(minValue, maxValue);
    std::vector<int> values;
    values.reserve(size);

    for (int i = 0; i < size; ++i) {
        values.push_back(distribution(generator));
    }

    return values;
}

std::vector<int> generateSortedVector(int size) {
    std::vector<int> values(size);
    for (int i = 0; i < size; ++i) {
        values[i] = i;
    }
    return values;
}

std::vector<int> generateReverseSortedVector(int size) {
    std::vector<int> values(size);
    for (int i = 0; i < size; ++i) {
        values[i] = size - i;
    }
    return values;
}

Duration measureHeapSort(const std::vector<int>& values) {
    auto copy = values;
    auto start = Clock::now();
    heap_sort::HeapSort::sort(copy);
    auto end = Clock::now();
    return end - start;
}

Duration measureStdSort(const std::vector<int>& values) {
    auto copy = values;
    auto start = Clock::now();
    std::sort(copy.begin(), copy.end());
    auto end = Clock::now();
    return end - start;
}

Duration averageDuration(const std::vector<int>& values, int trials, bool useHeapSort) {
    Duration total{0};
    for (int i = 0; i < trials; ++i) {
        total += useHeapSort ? measureHeapSort(values) : measureStdSort(values);
    }
    return total / trials;
}

void printVector(const std::vector<int>& values) {
    for (size_t i = 0; i < values.size(); ++i) {
        std::cout << values[i];
        if (i + 1 < values.size()) {
            std::cout << " ";
        }
    }
    std::cout << '\n';
}

void runDemo() {
    std::cout << "Heap Sort Demo\n";
    std::vector<int> values = generateRandomVector(20, 0, 99);
    std::cout << "Input values: ";
    printVector(values);

    heap_sort::HeapSort::sort(values);

    std::cout << "Sorted values:";
    std::cout << " ";
    printVector(values);
}

void runBenchmark() {
    std::vector<int> sizes = {1000, 10000, 100000};
    std::vector<std::string> inputs = {"random", "sorted", "reverse-sorted"};

    std::cout << "Benchmark: compare heap_sort against std::sort\n";
    std::cout << "Size,Input,HeapSort(ms),StdSort(ms)\n";

    for (int size : sizes) {
        for (const std::string& inputType : inputs) {
            std::vector<int> values;
            if (inputType == "random") {
            values = generateRandomVector(size);
        } else if (inputType == "sorted") {
            values = generateSortedVector(size);
        } else {
            values = generateReverseSortedVector(size);
        }

        Duration heapTime = averageDuration(values, 5, true);
        Duration stdTime = averageDuration(values, 5, false);

        std::cout << size << "," << inputType << ","
                  << heapTime.count() << "," << stdTime.count() << "\n";
        }
    }
}

void printHelp(const std::string& name) {
    std::cout << "Usage: " << name << " [--demo | --benchmark | --help]" << '\n';
    std::cout << "  --demo       Run a small heap sort demonstration." << '\n';
    std::cout << "  --benchmark  Measure heap sort and std::sort performance." << '\n';
    std::cout << "  --help       Show this help message." << '\n';
}

} // namespace

int main(int argc, char* argv[]) {
    std::string programName = argc > 0 ? argv[0] : "heap_sort_demo";

    if (argc == 1) {
        runDemo();
        return 0;
    }

    std::string option = argv[1];
    if (option == "--demo") {
        runDemo();
    } else if (option == "--benchmark") {
        runBenchmark();
    } else {
        printHelp(programName);
        return 1;
    }

    return 0;
}
