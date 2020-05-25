#include <bits/stdc++.h>
using namespace std;
char s[1100000],s1[1100000];
int neext[1100000];
void getnext(char s[],int nxt[])
{
	int i=0,j=-1;
	nxt[0]=-1;
	while(i<strlen(s)-1)
	{
		//cout<<"#"<<j<<endl;
		if(j==-1||s[i]==s[j])
		{
			i++;
			j++;
			nxt[i]=j;
		}
		else
			j=nxt[j];
	}
}
int kmp(char s1[],char s[],int nxt[])
{
	int i=0,j=0;
	if(strlen(s1)<strlen(s))
		return -2;
	int n=strlen(s1),m=strlen(s); 
	while(i<n&&j<m)
	{	
		//cout<<"Ç°i="<<i<<"  j="<<j<<endl;
		if(j==-1||s1[i]==s[j])
		{
			i++;
			j++;
		}
		else
			j=nxt[j];
		//cout<<"ºói="<<i<<"  j="<<j<<endl;
	}
	//cout<<j<<endl;
	if(j==m)
		return i-m;
	else
		return -2;
}
int main()
{
	
	cin>>s1;
	int n;
	cin>>n;
	while(n--)
	{
		cin>>s;	
		getnext(s,neext);
		/*for(int i=0;i<strlen(s);i++)
		{
			cout<<next[i]<<' ';
		}
		cout<<endl;*/
		int p=kmp(s1,s,neext);
		//cout<<p<<endl;
		if(p!=-2)
		{
			for(int i=p;i<strlen(s1);i++)
				cout<<s1[i];
			cout<<endl;
			//char *q=&s1[p];
			//cout<<*q<<endl;
		}		
		else
			cout<<"Not Found"<<endl;
	} 

}
/*
acabaabaabcacaabc
aabcac
*/
