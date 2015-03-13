#include <fstream>
#include <iostream>
#include <vector>
#include "vector_io.h"

int count_occurances(const std::vector<int>& v, int key, int lower, int upper)
{
    if (lower == upper) {
        return v[lower] == key ? 1 : 0;
    }
    int m = lower + (upper - lower) / 2;
    return count_occurances (v, key, lower, m) + count_occurances (v, key, m + 1, upper);
}

void test(const std::vector<int>& v, const std::vector<int>& tests)
{
    for (unsigned int i = 0; i < tests.size(); i++) {
        std::cout << "In " << v << std::endl;
        std::cout << tests[i] << " apare de "
                  << count_occurances(v, tests[i], 0, v.size() - 1)
                  << " ori." << std::endl;
        std::cout << std::endl;
    }
}

int main(void)
{
    std::ifstream f("date.in");
    std::vector<int> v1, t1, v2, t2;
    f >> v1 >> t1 >> v2 >> t2;

    test(v1, t1);
    test(v2, t2);

    return 0;
}
