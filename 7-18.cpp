#include<iostream>
#include <queue>
using namespace std;
int s[1005][1005], n, m,book[1005];
int bfs(int p)
{
	for (int i = 1; i <= n; i++)
		book[i] = 0;
	queue<int> q;
	q.push(p);
	int deep = 1;
	book[p] = 1;
	int sum = 1;
	while (!q.empty() && deep <= 6)
	{
		queue<int> lq;//Õ»Ò²¿É°É
		deep++;
		while (!q.empty())
		{
			int a = q.front();
			q.pop();
			for (int i = 1; i <= n; i++)
			{
				if (s[a][i] && book[i] == 0)
				{
					book[i] = 1;
					lq.push(i);
					sum++;p
				}
			}
		}
		while (!lq.empty())
		{
			q.push(lq.front());
			lq.pop();
		}
	}
	return sum;
}

int main()
{
	cin >> n >> m;
  for(int i = 1;i<=n;i++)
        for(int j = 1;j<=n;j++)
            s[i][j] = 0;  
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		s[a][b] = s[b][a] = 1;
	}
	for (int i = 1; i <= n; i++)
	{
		int sum = bfs(i);
		double ans;
		ans = sum *100/n*1.0;
		printf("%d: %.2f%%\n", i, ans);
	}
}
