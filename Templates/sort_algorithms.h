#pragma once
#include "vector.h"

class SortAlgorithms {
public:
  
    template<typename T>
    static void bubble_sort(Vector<T>& vec);

    template<typename T>
    static void quick_sort(Vector<T>& vec, int low, int high);

 
    template<typename Container, typename Function>
    static void transform(Container& container, Function func) {
        auto it = container.begin();
        auto end = container.end();
        while (it != end) {
            *it = func(*it);
            ++it;
        }
    }

    template<typename Container, typename Predicate>
    static Container filter(const Container& container, Predicate pred) {
        Container result;
        auto it = container.begin();
        auto end = container.end();
        while (it != end) {
            if (pred(*it)) {
                result.push_back(*it);
            }
            ++it;
        }
        return result;
    }

    template<typename Container, typename T, typename Function>
    static T reduce(const Container& container, T initial, Function func) {
        T result = initial;
        auto it = container.begin();
        auto end = container.end();
        while (it != end) {
            result = func(result, *it);
            ++it;
        }
        return result;
    }

private:
    template<typename T>
    static int partition(Vector<T>& vec, int low, int high);
};