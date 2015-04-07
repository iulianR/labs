/* Bivol Mihai - Laborator PA 01 2013 */
#ifndef __VECTOR_H__
#define __VECTOR_H__
#include <vector>

template <class T>
std::ostream& operator<<(std::ostream& stream, std::vector<T> vector)
{
    for (unsigned int i = 0; i < vector.size(); i++) {
        stream << vector[i] << " ";
    }
    return stream;
}

template <class T>
std::istream& operator>>(std::istream& stream, std::vector<T>& vector)
{
    unsigned int n;
    stream >> n;
    for (unsigned int i = 0; i < n; i++) {
        T x;
        stream >> x;
        vector.push_back(x);
    }
    return stream;
}

#endif
