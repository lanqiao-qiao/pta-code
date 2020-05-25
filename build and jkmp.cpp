#include <iostream>
#include <cstring>
using namespace std;
char s[1000010],p[11][100010];
int n1[1000010],n2[1000010];
int build(char x[],int next[])
{
	int i,j;
	next[0]=-1;
	for(j=1;j<strlen(x);j++)
	{
		i=next[j-1];
		while(i>=0&&x[j]!=x[i+1])
			i=next[i];
		if(x[i+1]==x[j])
			next[j]=i+1;
		else
			next[j]=-1;
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
		if(x[++i]==x[++j])
			next[i]=next[j];
		else
			next[i]=j;
	}
}
int jkmp(char x[],char y[],int next[])//xÄ£Ê½,yÖ÷´® 
{
	for(int i=0;i<strlen(x);i++)
		cout<<next[i]<<' ';
	cout<<endl;
	int i=0,j=0;
	int ans=-1;
	while(i<strlen(y))
	{
		if(y[i]==x[j])
		{
			i++;
			j++;
		}
		else
		{
			if(j>0)
				j=next[j-1]+1;
			else if(j==0)
				i++;
		}
		if(j==strlen(x))
		{
			ans=j-strlen(x);
			return ans;
		}
	}
	return ans;
}
int main()
{
	scanf("%s", s);
	build(s,n1);
	getnext2(s,n2);
	for(int i=0;i<strlen(s);i++)
	{
		cout<<n1[i]<<' ';
	 } 
	 cout<<endl;
	for(int i=0;i<strlen(s);i++)
	{
		cout<<n2[i]<<' ';
	 } 
	 cout<<endl;
}
