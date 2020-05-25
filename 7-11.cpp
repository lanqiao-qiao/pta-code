#include <iostream>
using namespace std;
int a[1050];
int ans;
int judgeroot(int x,int y)
{
	while(1)
	{
		if(x>y)
			x/=2;
		else if(x<y)
			y/=2;
		if(x==y)
		{
			ans=x;
			return a[x];
		}
	}
	
		
}
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	int ai,aj;
	cin>>ai>>aj;
	int ans2=judgeroot(ai,aj);
	if(a[ai]==0)
		printf("ERROR: T[%d] is NULL\n",ai);
	else if(a[aj]==0)
		printf("ERROR: T[%d] is NULL\n",aj);
	else
		cout<<ans<<' '<<ans2<<endl;
}
