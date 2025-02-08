#include "sort_algorithms.h"

template<typename T>
void SortAlgorithms::bubble_sort(Vector<T>& vec) {
    for (size_t i = 0; i < vec.size() - 1; ++i)
        for (size_t j = 0; j < vec.size() - i - 1; ++j)
            if (vec[j] > vec[j + 1])
                std::swap(vec[j], vec[j + 1]);
}

template<typename T>
void SortAlgorithms::quick_sort(Vector<T>& vec, int low, int high) {
    if (low < high) {
        int pivot_index = partition(vec, low, high);
        quick_sort(vec, low, pivot_index - 1);
        quick_sort(vec, pivot_index + 1, high);
    }
}

template<typename T>
int SortAlgorithms::partition(Vector<T>& vec, int low, int high) {
    T pivot = vec[high];
    int i = low - 1;
    for (int j = low; j < high; ++j)
        if (vec[j] <= pivot)
            std::swap(vec[++i], vec[j]);
    std::swap(vec[i + 1], vec[high]);
    return i + 1;
}


template void SortAlgorithms::quick_sort<int>(Vector<int>&, int, int);