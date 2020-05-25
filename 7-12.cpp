#include <iostream>
#include <queue>
using namespace std;
int s[15][15],book[15],book2[15];
int a,b;
queue<int> q;
void dfs(int x)
{
	book[x]=1;
	cout<<x<<' ';
	for(int i=0;i<a;i++)
	{
		if(s[x][i]==1&&book[i]==0)
		{
			//cout<<i<<'@'<<endl;
			book[i]=1;
			dfs(i);
		}
	}
}
void bfs(int x)
{
	q.push(x);
	while(q.size())
	{
		int y=q.front();
		book2[y]=1;
		cout<<y<<' ';
		q.pop();
		for(int i=0;i<a;i++)
		{
			if(s[y][i]==1&&book2[i]==0)
			{
				q.push(i);
				book2[i]=1;
			}
				
		}
	}
}
int main()
{
	cin>>a>>b;
	for(int i=0;i<b;i++)
	{
		int x,y;
		cin>>x>>y;
		s[x][y]=s[y][x]=1;
	}
	/*cout<<"  ";
	for(int i=0;i<b;i++)
		cout<<i<<' ';
	cout<<endl;
	for(int i=0;i<b;i++)
	{
		cout<<i<<' ';
		for(int j=0;j<b;j++)
		{
			cout<<s[i][j]<<' ';
		}
		cout<<endl;
	}*/
	for(int i=0;i<a;i++)
	{
		if(book[i]==0)
		{
			cout<<"{ ";
			dfs(i);
			cout<<"}"<<endl;
		}
	}
	for(int i=0;i<a;i++)
	{
		if(book2[i]==0)
		{
			cout<<"{ ";
			bfs(i);
			cout<<"}"<<endl;
		}
	}
}
