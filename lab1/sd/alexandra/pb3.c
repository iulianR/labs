#include <stdio.h>
#include <conio.h>

int isEven(int n);
int isOdd(int n);

int main()
{
    int n = 64;
    if(isEven(65))
        printf("Par");
    else
        printf("Impar");
    return 0;
}

int isEven(int n)
{
    if(n % 2 == 0)
        return 1;
    else
        return isOdd(n);
}

int isOdd(int n)
{
    if(n % 2 == 1)
        return 1;
    else
        return isEven(n);
}
