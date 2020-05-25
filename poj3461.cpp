#include <iostream>
#include <cstring>
using namespace std;
char s[1000010],p[1000010];
int n[1000010];
void getnext(char x[],int next[])
{
	int i,j;
	j=next[0]=-1;
	i=0;
	/*
	while(i<strlen(x))
	{
		while(j!=-1&&x[i]!=x[j])
			j=next[j];
		next[++i]=++j;
	}*/
	while(i<strlen(x))
	{
		while(j!=-1&&x[i]!=x[j])
			j=next[j];
		if(x[++i]==x[++j])
			next[i]=next[j];
		else
			next[i]=j;
	}
}
int kmp(char x[],char y[],int next[])//xÄ£Ê½´®,yÖ÷´®
{
	int n=strlen(x),m=strlen(y);
	int i=0,j=0,ans=0;
	while(i<m)
	{
		while(j!=-1&&y[i]!=x[j])
			j=next[j];
		i++,j++;
		if(j>=n)
		{
			ans++;
			j=next[j];
		}
	}
	return ans;
} 
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		cin>>p>>s;
		getnext(p,n);
		/*for(int i=0;i<strlen(s);i++)
		cout<<n[i]<<' ';
		cout<<endl;*/
		int ans=kmp(p,s,n);
		cout<<ans<<endl;
	} 
}
