#include <iostream>
#include <stack>
#include <map>
using namespace std;
int main()
{
	stack <char> a;
	stack <char> b;
	string s;
	map<char,char> m;
	m[')']='(';
	m[']']='[';
	m['}']='{';
	m['#']='#';
	//cout<<m['}'];
	int q=0;
	while(1)
	{
		cin>>s; 
		if(s==".")
			break;
		for(int i=0;i<=s.length();i++)
		{
			//cout<<s[i]<<endl;
			if(q==1)
				break;
			if(s[i]=='('||s[i]=='['||s[i]=='{')
				a.push(s[i]);
			else if(s[i]=='/'&&s[i+1]=='*')
			{
				a.push('#');
				i++;
			}
			else if(s[i]==')'||s[i]==']'||s[i]=='}')
			{
				if(!a.empty()&&a.top()==m[s[i]])
					a.pop();
				else
				{
					//cout<<s[i]<<endl;
					cout<<"NO"<<endl;
					q=1;
					if(a.empty())
						cout<<"?-"<<s[i]<<endl;
					else
					{
						if(a.top()=='#')
							cout<<"/*-?"<<endl;
						else 
							cout<<a.top()<<"-?"<<endl;	
					} 
					break;
				}
			}
			else if(s[i]=='*'&&s[i+1]=='/')
			{
				i++;
				if(!a.empty()&&a.top()==m['#'])
					a.pop();
				else
				{
					//cout<<s[i]<<endl;
					cout<<"NO"<<endl;
					q=1;
					if(a.empty())
						cout<<"?-"<<"*/"<<endl;
					else
					{
						if(a.top()=='#')
							cout<<"/*-?"<<endl;
						else 
							cout<<a.top()<<"-?"<<endl;	
					} 
					break;
				}
			}
		}
		//cout<<a.top()<<endl;
		//cout<<s<<endl;
	}
	if(q==0&&a.empty())
		cout<<"YES"<<endl;
	else if(q==0)
	{
		cout<<"NO"<<endl;
		if(a.top()=='#')
			cout<<"/*-?"<<endl;
		else 
			cout<<a.top()<<"-?"<<endl;
	}
}
