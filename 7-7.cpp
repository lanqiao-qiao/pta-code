#include <iostream>
#include <cstring>
using namespace std;
char s1[100050],s2[100050],*s;
int main()
{
	cin>>s1;
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>s2;
		s=strstr(s1,s2);
		if(s==NULL)
			cout<<"Not Found"<<endl;
		else
			cout<<s<<endl;
	}
}
