#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <climits>

#include "vector_io.h"

int maximum_crossing_subarray (std::vector<int> v, int lower, int mid, int upper)
{
    int left_sum = INT_MIN;
    int sum = 0;
    for (int i = mid; i > lower; i--) {
        sum += v[i];
        if (sum > left_sum) {
            left_sum = sum;
        }
    }
    int right_sum = INT_MIN;
    sum = 0;
    for (int j = mid + 1; j < upper; j++) {
        sum += v[j];
        if (sum >= right_sum) {
            right_sum = sum;
        }
    }

    return left_sum + right_sum;
}

int maximum_subarray (std::vector<int> v, int lower, int upper)
{
    if (lower == upper)
        return v[lower];
    else {
        int m = (lower + upper) / 2;
        int left_sum = maximum_subarray (v, lower, m);
        int right_sum = maximum_subarray (v, m + 1, upper);
        int cross_sum = maximum_crossing_subarray (v, lower, m, upper);
        if (left_sum >= right_sum && left_sum >= cross_sum)
            return left_sum;
        else if (right_sum >= left_sum && right_sum >= cross_sum)
            return right_sum;
        else
            return cross_sum;
    }
}

int main(void)
{
    std::ifstream f ("date.in");
    std::vector<int> v;
    v = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    std::cout << "v: " << v << std::endl;

    std::cout << "Suma maximă: " << maximum_subarray (v, 0, v.size ())<< std::endl;
    f.close();
}
