#include <stdio.h>

int prime_intre_ele(int a, int b)
{
    if (a == b)
        return 0;
    else if (a <= 1 || b <= 1)
        return 1;
    else if (a > b)
        return prime_intre_ele(a - b, b);
    else if (b > a)
        return prime_intre_ele(a, b - a);
}

int perechi_prime_intre_ele(int n, int v[])
{
    if (n <= 1)
        return 0;
    else {
        if (*v == v[n - 1]) {
                puts("once");
            return 1 + perechi_prime_intre_ele(n - 1, v - n + 1);

//        else if (prime_intre_ele(v[n - 1], *v))
//            return 1 + perechi_prime_intre_ele(n, v + 1);
        }
        else {
            puts("twice");
            return 1 + perechi_prime_intre_ele(n, v + 1);
        }
    }
}

int main()
{
    int n = 4, v[4] = {7, 21, 12, 16};
    printf("Nr = %d\n", perechi_prime_intre_ele(n, v));
    return 0;
}
