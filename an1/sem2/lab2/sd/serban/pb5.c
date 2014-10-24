#include <stdio.h>
 
void swap(char *a, char *b);  
void perm(char *a, int i, int n); 
 
int main()
{
   char a[] = "abc";  
   perm(a, 0, 2);
   return 0;
}

void perm(char *a, int i, int n)
{
   int j; 
   if (i == n)
     printf("%s\n", a);
   else {
        for (j = i; j <= n; j++) {
          swap(a + i, a + j);
          perm(a, i + 1, n);
          swap(a + i, a + j); 
       }
   }
} 

void swap(char *a, char *b)
{
    char aux;
   	aux = *a;
    *a = *b;
    *b = aux;
}
