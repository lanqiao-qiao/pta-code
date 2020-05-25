#include <iostream>
#include <cstring>
using namespace std;
char s[1000010], p[100010];
void build(char x[], int next[])
{
	int i, j;
	next[0] = -1;
	for (j = 1; j < strlen(x); j++)
	{
		i = next[j - 1];
		while (i >= 0 && x[j] != x[i + 1])
			i = next[i];
		if (x[i + 1] == x[j])
			next[j] = i + 1;
		else
			next[j] = -1;
	}
}
int jkmp(char x[], char y[])//xÄ£Ê½,yÖ÷´® 
{
	int i = 0, j = 0;
	int ans = -1;
	if(strlen(x)>strlen(y))
		return -1;
	int next[100010];
	build(x,next); 
	while (i < strlen(y))
	{
		//cout << "@" << i << endl;
		if (y[i] == x[j])
		{
			i++;
			j++;
		}
		else
		{
			if (j > 0)
				j = next[j - 1] + 1;
			else if (j == 0)
				i++;
		}
		if (j == strlen(x))
		{
			ans = i - strlen(x);
			return ans;
		}
	}
	return ans;
}
int main()
{
	scanf("%s", s);
	int t;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%s", p);
		int ans = jkmp(p, s);
		//printf("%d\n", ans);
		if (ans == -1)
			printf("Not Found\n");
		else
		{
			for (int i = ans; i <= strlen(s); i++)
				printf("%c", s[i]);
			printf("\n");
		}
	}
}
