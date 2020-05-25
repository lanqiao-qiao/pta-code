#include <iostream>
#include <cstring>
#include <cstdio>
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
void getnext2(char x[],int next[])
{
	int i,j;
	j=next[0]=-1;
	i=0;
	while(i<strlen(x))
	{
		while(j!=-1&&x[i]!=x[j])
			j=next[j];
		next[++i]=++j;
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
			cout<<i-strlen(x)<<endl;
		}
	}
	return ans;
}
int main()
{
	scanf("%s%s",s,p);
	getnext(p,n);
	for(int i=0;i<strlen(p);i++)
		cout<<p[i]<<n[i]<<' ';
	cout<<endl;
	int ans=kmp(p,s,n);
	printf("%d\n",ans); 
}
/*
acabaabaabcacaabc
aabcac
#include <iostream>
#include <cstring>
using namespace std;
void getnext(char x[],int next[])
{
	int i,j;
	j=next[0]=-1;
	i=0;
	while(i<strlen(x))
	{
		while(j!=-1&&x[i]!=x[j])
			j=next[j];
		next[++i]=++j;
	}
}
void getnextval(char x[],int next[])
{
	int i,j;
	j=next[0]=-1;
	i=0;
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
int main()
{
	char s[10000];
	int n1[10000],n2[10000];
	memset(n1,0,sizeof(n1));
	memset(n2,0,sizeof(n2));
	cin>>s;
	getnext(s,n1);
	getnextval(s,n2);
	for(int i=0;i<strlen(s);i++)
		cout<<n1[i]+1<<' ';
	cout<<endl;
	for(int i=0;i<strlen(s);i++)
		cout<<n2[i]+1<<' ';
	cout<<endl;
}
*/
