#include <iostream>
using namespace std;
int a[2005],b[2005],x[2005],y[2005];
int main()
{
	int la,lb,m,n;
	cin>>la;
	for(int i=0;i<la;i++)
	{
		cin>>m>>n;
		a[n]=m;
	}
	cin>>lb;
	for(int i=0;i<lb;i++)
	{
		cin>>m>>n;
		b[n]=m;
	}
	for(int i=0;i<2004;i++)
	{
		if(a[i])
		{
			//cout<<i<<endl;
			for(int j=0;j<2004;j++)
			{
				if(b[j])
				{
					x[i+j]+=a[i]*b[j];
					//cout<<i<<' '<<j<<' '<<a[i]<<' '<<b[j]<<endl;
				}
			}
		}
	}
	int q=0;
	for(int i=2004;i>=0;i--)
	{
		if(x[i])
		{
			if(q==0)
			{
				cout<<x[i]<<' '<<i;
				q=1;
			}
			else
				cout<<' '<<x[i]<<' '<<i;		
		}
	}
	if(!q)
		cout<<"0 0";
	cout<<endl;
	for(int i=0;i<2004;i++)
	{
		if(a[i])
			y[i]+=a[i];
		if(b[i])
			y[i]+=b[i];
	}
	q=0;
	for(int i=2004;i>=0;i--)
	{
		if(y[i])
		{
			if(q==0)
			{
				cout<<y[i]<<' '<<i;
				q=1;
			}
			else
				cout<<' '<<y[i]<<' '<<i;		
		}
	}
	if(!q)
		cout<<"0 0";
}
