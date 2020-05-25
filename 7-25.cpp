#include <iostream>
#include <algorithm>
using namespace std;
typedef unsigned long long llu;
llu s[1000050];
llu cmp(llu a,llu b)
{
	return a>b;
}
int main()
{
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++)
		cin>>s[i];
	sort(s,s+n,cmp);
	for(int i=0;i<m;i++)
	{
		if(i==0)
			cout<<s[i];
		else
			cout<<' '<<s[i];
	}
}
