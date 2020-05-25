#include <iostream>
#include <map>
using namespace std;
int main()
{
	map<string,string> m;
	int n;
	char ch;
	string s1,s2;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>ch>>s1>>s2;
		if(ch=='N')
		{
			if(m.find(s1)==m.end())
			{
				cout<<"New: OK"<<endl;
				m[s1]=s2;
			}
			else
				cout<<"ERROR: Exist"<<endl;
		}
		else
		{
			if(m.find(s1)==m.end())
				cout<<"ERROR: Not Exist"<<endl;
			else
			{
				if(m[s1]==s2)
					cout<<"Login: OK"<<endl;
				else
					cout<<"ERROR: Wrong PW"<<endl;
			}
		}
	}
}
