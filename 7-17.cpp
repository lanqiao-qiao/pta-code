#include <iostream>
#include <algorithm>
using namespace std;
int n, m, s, dd, q;
struct high
{
	int l, p;
}e[505][505],dis[505], mmin;
int book[505];
int main()
{
	cin >> n >> m >> s >> dd;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i == j)
				e[i][j].l =e[i][j].p= 0;
			else
				e[i][j].l =e[i][j].p= 9999;
		}
	}//init
	for (int i = 0; i < m; i++)
	{
		int a, b, c,d;
		cin >> a >> b >> c >> d;
		e[a][b].l = e[b][a].l = c;
		e[a][b].p = e[b][a].p = d;
	}
	for (int i = 0; i < n; i++)
	{
		dis[i].l = e[s][i].l;
		dis[i].p = e[s][i].p;
	}
	book[s] = 1;
	for (int i = 0; i < n; i++)
	{
		mmin.l = 999999;
		for (int j = 0; j < n; j++)
		{
			if (dis[j].l < mmin.l && book[j] == 0)
			{
				mmin = dis[i];
				q = j;
			}
		}
		book[q] = 1;
		for (int j = 0; j < n; j++)
		{
			if (e[q][j].l < 999999)
			{
				if (dis[j].l > dis[q].l + e[q][j].l)
				{
					dis[j].l = dis[q].l + e[q][j].l;
					dis[j].p = dis[q].p + e[q][j].p;
				}
				else if (dis[j].l == dis[q].l + e[q][j].l)
				{
					dis[j].p = min(dis[j].p, dis[q].p + e[q][j].p);
				}
			}
		}
	}
	cout << dis[dd].l << ' ' << dis[dd].p << endl;
}
