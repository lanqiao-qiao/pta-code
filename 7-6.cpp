#include <iostream>
#include <stack>
using namespace std;
int main()
{
	stack<int> a,b;
	int m,n;
	cin>>m>>n;
	if(m>n)
		swap(m,n);
	char x;
	int y;
	while(cin>>x)
	{
		if(x=='T')
			break;
		else if(x=='A')
		{
			cin>>y;
			if(a.size()<m)
				a.push(y);
			else
			{
				if(b.size()==0)
				{
					while(!a.empty())
					{
						b.push(a.top());
						a.pop();	
					}
					a.push(y);	
				}
				else
				{
					cout<<"ERROR:Full"<<endl;
				}
			}	
		}
		else if(x=='D')
		{
			if(b.size()==0)
			{
				if(a.size()==0)
				{
					cout<<"ERROR:Empty"<<endl;
					continue;
				}
				else
					while(!a.empty())
					{
						b.push(a.top());
						a.pop();	
					}
			}
			cout<<b.top()<<endl;
			b.pop();
		}
		
	}
}
