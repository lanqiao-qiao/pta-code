#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
char s[1000010], p[11][1000010];
int n[1000010];
void getnext2(char x[], int next[])
{
	int i, j;
	j = next[0] = -1;
	i = 0;
	while (i < strlen(x))
	{
		while (j != -1 && x[i] != x[j])
			j = next[j];
		next[++i] = ++j;
	}
}
int kmp(char x[], char y[], int next[])//xÄ£Ê½´®,yÖ÷´®
{
	int n = strlen(x), m = strlen(y);
	int i = 0, j = 0, ans = 0;
	while (i < m)
	{
		while (j != -1 && y[i] != x[j])
			j = next[j];
		i++, j++;
		if (j >= n)
		{

			return i - strlen(x);
		}
	}
	return -1;
}
int main()
{
	scanf("%s", s);
	int t;
	scanf("%d", &t);
	while (t--)
	{
		int k = 0;
		scanf("%s", p[k]);
		getnext2(p[k], n);
		int ans = kmp(p[k], s, n);
		//printf("%d\n", ans);
		if (ans == -1)
			printf("Not Found");
		else
		{
			for (int i = ans; i <= strlen(s); i++)
				printf("%c", s[i]);
		}
		if(t)
			printf("\n");
		k++;
	}
}

