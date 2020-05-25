#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
int a[10050][15];
double good[10050];
double cmp(double a,double b)
{
	return a>b;
}
int main()
{
	int n,k,m;
	cin>>n>>k>>m;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<k;j++)
		{
			cin>>a[i][j];
		}
	}
	for(int i=0;i<n;i++)
	{
		sort(a[i],a[i]+k);
		double sum=0;
		for(int j=1;j<k-1;j++)
		{
			sum+=a[i][j];
		}
		good[i]=sum/(k-2);
	}
	sort(good,good+n,cmp);
	for(int i=m-1;i>=0;i--)
	{
		if(i==m-1)
			printf("%.3f",good[i]);
		else
			printf(" %.3f",good[i]);
	}
} 
