#include <stdio.h>

int atoin(char *s, int n);

int main()
{
    char s[] = {"45127"};
    int n = 5;
    printf("nr = %d\n", atoin(s, n - 1));
    return 0;
}

int atoin(char *s, int n)
{
    if (n < 0)
        return 0;
    else return
        (s[n] - '0') + 10 * atoin(s, n - 1);
}
