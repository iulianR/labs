#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <algorithm>

#include "complex.h"

bool operator<(const Complex &a, const Complex &b)
{
    //TODO Intoarceti true daca a < b, fals altfel
    if (a.r < b.r) {
        return true;
    }
    else if (a.r == b.r) {
        if (a.i < b.i) {
            return true;
        }
    }

    return false;
}

bool operator==(const Complex &a, const Complex &b)
{
    return (a.r == b.r && a.i == b.i);
}

std::vector<Complex> get_sorted(const std::vector<Complex> &v)
{
    std::vector<Complex> res;
    //TODO Folosind priority_queue, adaugati elementele din v în ordine descrescătoare.
    std::priority_queue<Complex> queue;
    for (unsigned int i = 0; i < v.size(); i++) {
        queue.push (v[i]);
    }

    while (!queue.empty()) {
        res.push_back (queue.top());
        queue.pop ();
    }

    return res;
}

std::map<Complex, int> get_mapping(const std::vector<Complex> &v)
{
    std::map<Complex, int> res;
    //TODO Adăugati în map, pentru fiecare element din v, poziția sa în vectorul sortat.
    std::vector<Complex> sorted = get_sorted(v);

    std::vector<Complex>::iterator it;
    for (unsigned int i = 0; i < v.size (); i++) {
        it = std::find (sorted.begin (), sorted.end (), v[i]);
        res.insert (std::pair<Complex, int>(v[i], it - sorted.begin ()));
    }
    return res;
}

int main(void)
{
    std::vector<Complex> v;
    // Citeste date de test.
    v = read_data(".date.in");
    std::cout << "Vectorul initial" << std::endl;
    write_vector(v);

    // Verifica sortarea.
    std::vector<Complex> sorted = get_sorted(v);
    std::cout << "Vectorul sortat" << std::endl;
    write_vector(sorted);

    // Verifica maparea.
    std::cout << "Maparea" << std::endl;
    std::map<Complex, int> mapping = get_mapping(v);

    for (unsigned int i = 0; i < sorted.size(); i++)
    {
        std::cout << sorted[i] << " e pe pozitia "
                  << mapping[sorted[i]] << std::endl;
    }

    return 0;
}
