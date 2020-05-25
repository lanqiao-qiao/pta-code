#include <iostream>
#include <algorithm>
typedef unsigned long long llu;
using namespace std;
int s[100050];
int main()
{
	int n;
	llu sum=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&s[i]);
		sum+=s[i];
	}
	sort(s,s+n);
	//cout<<"@"<<endl;
	llu sum2=0;
	for(int i=0;i<n/2;i++)
	{
		sum2+=s[i];
	}
	int x,y;
	if(n%2)
	{
		x=n/2+1;
		y=n/2;
	}
	else
	{
		x=y=n/2;
	}
	printf("Outgoing #: %d\n",x);
	printf("Introverted #: %d\n",y);
	printf("Diff = %llu\n",sum-sum2-sum2);
}
