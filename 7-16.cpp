#include <iostream>
int s[105][105],n,m;;
using namespace std;
void print(int s[][105]);
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		{
			if(i==j)
				s[i][j]=0;
			else
				s[i][j]=999;
		}
	for(int i=0;i<m;i++)
	{
		int a,b,c;
		cin>>a>>b>>c;
		s[a][b]=s[b][a]=c;
	}
//	print(s);
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				if(s[i][j]>s[i][k]+s[k][j])
					s[i][j]=s[i][k]+s[k][j];
	print(s);
	int minn=99999,min_i,q=0;
	for(int i=1;i<=n;i++)
	{
		int maxx=-1;
		for(int j=1;j<=n;j++)
		{
			if(s[i][j]==999)
			{
				q=1;
				break;
			}
			if(s[i][j]>maxx)
				maxx=s[i][j];
		}
		if(maxx<minn)
		{
			minn=maxx;
			min_i=i;	
		}
	}
	if(q)
		cout<<0<<endl;
	else
		cout<<min_i<<' '<<minn<<endl;
}
void print(int s[][105])
{
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cout<<s[i][j]<<' ';	
		}	
		cout<<endl;
	}	
}
