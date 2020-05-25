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
