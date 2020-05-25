#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
using namespace std;
typedef unsigned long long llu;
vector <llu> s;
bool cmp(llu a,llu b)
{
	return a>b;
}
int main()
{
	int n,m,a;
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a);
		s.push_back(a);
	}
	sort(s.begin(),s.end(),cmp);
	for(int i=0;i<m&&i<n;i++)
	{
		if(i==0)
			printf("%d",s[i]);
		else
			printf(" %d",s[i]);
	}
}
