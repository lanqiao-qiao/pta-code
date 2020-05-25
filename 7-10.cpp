#include <iostream>
#include <queue>
using namespace std;
int main()
{
	int n;
	cin>>n;
	priority_queue<int,vector<int>,greater<int> > q;
	for(int i=0;i<n;i++)
	{
		int a;
		cin>>a;
		q.push(a);
	}
	int ans,sum=0;
	while(q.size()!=1)
	{
		int a=q.top();
		q.pop();
		int b=q.top();
		q.pop();
		ans=a+b;
		//cout<<ans<<endl;
		sum+=ans;
		q.push(ans);
	}
	cout<<sum<<endl;
}
