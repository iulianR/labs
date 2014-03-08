#include <stdio.h>
#include <string.h>

void swap(char *i, char *j)
{
	char t;
	t=*i;
	*i=*j;
	*j=t;
}
void perm(char *str, int i, int n)
{

	int j;
	if (i == n) {
		printf("%s ", str);
	}
	else {
		for(j=i;j<=n;j++)
		{
			swap(str+i,str+j);
			perm(str,i+1,n);
			swap(str+i,str+j);
		}
	}
}

int main()
{
	char string[10000] = {'a', 'b', 'c'};
	int n;

	n=strlen(string);
	perm(string, 0, n-1);
	printf("\n");

	return 0;
}
