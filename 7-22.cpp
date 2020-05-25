#include <iostream>
#include <algorithm>
using namespace std;
int a[100050];
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	sort(a,a+n);
	for(int i=0;i<n;i++)
	{
		if(i==0)
			cout<<a[i];
		else
			cout<<' '<<a[i];
	}
	cout<<endl;
}
