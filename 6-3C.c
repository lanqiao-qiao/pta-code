#include <stdio.h>
#include <stdlib.h>

void printArray(int* arr, int arr_size);          /* ????,???? */
void merge(int* a, int m, int* b, int n, int* c); /* ??a?b?c */

int main(int argc, char const *argv[])
{
    int m, n, i;
    int *a, *b, *c;

    scanf("%d", &m);
    a = (int*)malloc(m * sizeof(int));
    for (i = 0; i < m; i++) {
        scanf("%d", &a[i]);
    }

    scanf("%d", &n);
    b = (int*)malloc(n * sizeof(int));
    for (i = 0; i < n; i++) {
        scanf("%d", &b[i]);
    }
    c = (int*)malloc((m + n) * sizeof(int));
    merge(a, m, b, n, c);
    printArray(c, m + n);

    return 0;
}
void merge(int* a, int m, int* b, int n, int* c)
{
	int ia=0,ib=0,ic=0;
	int mm=m,nn=n;
	while(m!=0&&n!=0)
	{
		if(a[ia]<=b[ib])
		{
			c[ic++]=a[ia++];
			m--; 
		}
		else
		{
			c[ic++]=b[ib++];
			n--;
		}
	}
	if(m==0)
	{
		int num=n;
		while(num--)
		c[ic++]=b[ib++];
	}
	if(n==0)
	{
		int num=m;
		while(num--)
		c[ic++]=a[ia++];
	}
}
void printArray(int* arr, int arr_size)
{
	int i;
	printf("%d",arr[0]);
	for(i=1;i<arr_size;i++)
		printf(" %d",arr[i]);
}



















