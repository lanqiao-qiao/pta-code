#include <iostream>
#include <algorithm>
using namespace std;
int f[1050];
struct load
{
	int x;
	int y;
	int lens;
}L[3050];
int cmp(struct load a,struct load b)
{
	return a.lens<b.lens;
}
int getf(int x)//²¢²é¼¯ 
{
	if(f[x]==x)
		return x;
	else
		return getf(f[x]);
}
int merge(int x,int y)
{
	int a=getf(x),b=getf(y);
	if(a!=b)
	{
		f[a]=b;
		return 1;
	}
	return 0;
}
int main()
{
	int n,m,sum=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		f[i]=i;
	for(int i=0;i<m;i++)
	{
		cin>>L[i].x>>L[i].y>>L[i].lens;
	}
	sort(L,L+m,cmp);
	for(int i=0;i<m;i++)
	{
		if(merge(L[i].x,L[i].y)==1)
		{
			sum+=L[i].lens;
			n--;
		}
	}
	if(n==1)
		cout<<sum<<endl;
	else
		cout<<-1<<endl;
}
