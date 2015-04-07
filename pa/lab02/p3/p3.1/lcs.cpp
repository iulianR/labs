#include <fstream>
#include <iostream>
#include <vector>
#include "vector_io.h"

#define MAX_N 1001

void create_table(std::vector<int>& v1, std::vector<int>& v2, std::vector<std::vector<int> >& lsc)
{
    int i, j;
    for(i = 1; i < (int) v1.size (); i++) {
        for(j = 0; j < (int) v2.size (); j++) {
            if(v1[i] == v2[j]) {
                lsc[i][j] = 1;
            }
        }
    }
}

void create_solution(std::vector<int>& sol, std::vector<std::vector<int> >& lsc, std::vector<int>& v, int linie, int col, int n)
{
    if (col == n || linie == (int) v.size ())
        return;
    int i;
    for(i = linie; i < (int) v.size (); i++)
        if (lsc[i][col] == 1) {
            sol.push_back (v[i]);
            create_solution (sol, lsc, v, i + 1, col + 1, n);
            return;
        }
    create_solution (sol, lsc, v, linie, col + 1, n);
}

std::vector<int> longest_common_subset(std::vector<int>& v1, std::vector<int>&v2)
{
    std::vector<std::vector<int> > lsc(v1.size() + 1,
                                       std::vector<int>(v2.size() + 1, 0));
    std::vector<int> sol;

    // TODO
    // Gasiti cel mai lung subsir comun pentru vectorii v1 si v2.
    //
    // ATENTIE: vectorii au -1 pe poziția 0, valoare ce va fi ignorată. S-a
    // ales această variantă pentru a fi mai usor de implementat recurenta și
    // a putea în același timp folosi vector_io.
    //
    // Practic, indexarea este [1, ..,  v.size() - 1]

    create_table (v1, v2, lsc);
    create_solution (sol, lsc, v1, 1, 1, (int) v2.size ());

    return sol;
}

void test(std::vector<int>& v1, std::vector<int>& v2)
{
    // ATENTIE: vectorii au -1 pe poziția 0, valoare ce va fi ignorată în
    // rezolvare, dar care va apărea la citire și afisare.

    std::cout << "Pentru vectorii:" << std::endl;
    std::cout << v1 << std::endl << v2 << std::endl;
    std::cout << "Rezultatul este:" << std::endl;
    std::cout << longest_common_subset(v1, v2) << std::endl << std::endl;
}

int main(void)
{
    std::ifstream f("date.in");
    std::vector<int> v1, v2;

    f >> v1 >> v2;
    test(v1, v2);

    v1.clear(); v2.clear();

    f >> v1 >> v2;
    test(v1, v2);

    return 0;
}
