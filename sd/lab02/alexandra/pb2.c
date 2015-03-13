#include <stdio.h>

int y = 0;
int control(int);

int main()
{
    int x = 98976;
    printf("Cifra de control = %d\n", control(x));
    printf("y = %d\n", y);
    return 0;
}

int control(int x)
{
    if (x == 0) {
        return 0;
    }
    else{
        printf("%d\n", x);
        y = x % 10 + control(x/10);
    }
    if (y > 9) {
        x = y;
        y = control(x);
    }
}
