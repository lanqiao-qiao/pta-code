#include <iostream>
#include <queue>
using namespace std;
int main()
{
	queue<int> a,b;
	int n,m;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>m;
		if(m%2==0)
			b.push(m);
		else
			a.push(m);
	}
	int q=0;
	for(int i=0;i<2*n;i++)
	{
		//cout<<"!"<<endl;
		if(a.empty()&&b.empty())
			break;
		if(!a.empty())
		{
			if(q==0)
			{
				cout<<a.front();
				q=1;
			}
			else
				cout<<" "<<a.front();
			a.pop();
		}
		if(i%2&&i!=0)
		{
			if(!b.empty())
			{
				if(q==0)
				{
					cout<<b.front();
					q=1;
				}
				else
					cout<<" "<<b.front();
				b.pop();
			}
		}
	}
	cout<<endl;
}
