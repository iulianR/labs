#include <iostream>
#include <fstream>
#include <vector>

#include "vector_io.h"

void swap (int &x, int &y) {
    int temp;

    temp = x;
    x = y;
    y = temp;
}

int partition (std::vector<int> &v, int lower, int upper)
{
    int x = v[upper];
    int i = lower - 1;
    for (int j = lower; j < upper; j++) {
        if (v[j] <= x) {
            i ++;
            swap (v[i], v[j]);
        }
    }
    swap (v[i + 1], v[upper]);
    return i + 1;
}

void qsort(std::vector<int> &v, int lower, int upper)
{
    //TODO Completati codul pentru a realiza quicksort
    if (lower < upper) {
        int m = partition (v, lower, upper);
        qsort (v, lower, m - 1);
        qsort (v, m + 1, upper);
    }
}

int partition2 (std::vector<int> &v, int lower, int upper, int pivot_index) {
    int pivot = v[pivot_index];
    swap (v[pivot_index], v[upper]);
    int store_index = lower;
    for (int i = lower; i < upper; i++) {
        if (v[i] < pivot) {
            swap (v[i], v[store_index]);
            store_index++;
        }
    }
    swap (v[upper], v[store_index]);
    return store_index;
}

int find_kth_min(std::vector<int> &v, int lower, int upper, int k)
{
    // TODO Completati codul pentru a afla al k-lea minim din vectorul v
    while (upper >= lower) {
        int pivot_index = partition2 (v, lower, upper, lower + (upper - lower) / 2);
        if (pivot_index == k) {
            return v[pivot_index];
        } else if (pivot_index < k) {
            lower = pivot_index + 1;
        } else {
            upper = pivot_index - 1;
        }
    }
    return 0;
}

int main(void)
{
    std::ifstream f("date.in");
    std::vector<int> v1, v2;
    f >> v1;
    f >> v2;
    std::cout << "v1: " << v1 << std::endl;
    for (unsigned int i = 0; i < v1.size(); i++) {
        std::cout << "Al " << i << "-lea minim din v1 este: ";
        std::cout << find_kth_min(v1, 0, v1.size() - 1, i) << std::endl;
    }
    qsort(v1, 0, v1.size() - 1);
    qsort(v2, 0, v2.size() - 1);
    std::cout << "Vectorii sortati:\n";
    std::cout << v1 << std::endl;
    std::cout << v2 << std::endl;
    f.close();
}
