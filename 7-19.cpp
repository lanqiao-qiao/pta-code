#include <iostream>
#include <cstring> 
using namespace std;
int main()
{
	int a[10000],b[10000];
	int n,m;
	while(cin>>n)
	{
		//cin>>n>>m;
		if(n==0)
			break;
		cin>>m;
		memset(a,0,sizeof(a));
		for(int i=0;i<n;i++)
		{
			int q=1,x;
			cin>>x;
			while(1)
			{
				if(a[q]==0)
				{
					a[q]=x;
					break;
				}
				else if(x<a[q])
				{
					q=q*2;
				}
				else
					q=q*2+1;
			}
		}
		//cout<<"@"<<endl;	
		for(int i=0;i<m;i++)
		{
			//cout<<"%"<<endl;
			memset(b,0,sizeof(b));
			for(int j=0;j<n;j++)
			{
				int q=1,x;
				cin>>x;
				while(1)
				{
					if(b[q]==0)
					{
						b[q]=x;
						break;
					}
					else if(x<b[q])
					{
						q=q*2;
					}
					else
						q=q*2+1;
				}
			}
			int p=0;
			for(int i=1;i<10000;i++)
			{
				if(a[i]!=b[i])
				{
					p=1;
					break;
				}
			}
			if(p==1)
				cout<<"No"<<endl;
			else
				cout<<"Yes"<<endl;
		}
	
	}
	
}
