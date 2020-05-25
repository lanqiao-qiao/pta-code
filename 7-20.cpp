#include <iostream> 
#include <map>
using namespace std;
int main()
{
	map<string,int> s;
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		string a,b;
		cin>>a>>b;
		s[a]++;
		s[b]++;
	}
	string c;
	int max=-1;
	for(map<string,int>::iterator i=s.begin();i!=s.end();i++)
	{
		if(i->second>max)
		{
			c=i->first;
			max=i->second;
		}
		else if(i->second==max)
		{
			if(i->first<c)
			{
				max=i->second;
				c=i->first;
			}
		}
	}
	int m=0;
	for(map<string,int>::iterator i=s.begin();i!=s.end();i++)
	{
		if(i->second==max)
			m++;
	}
	if(m!=1)
		cout<<c<<' '<<max<<' '<<m<<endl;
	else
		cout<<c<<' '<<max<<endl;
}
