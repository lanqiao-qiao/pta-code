#include <iostream>
#include <map>
#include <stack>
#include <string> 
using namespace std;
int main()
{
	stack<char> st;
	map<char,int> m;
	m['+']=m['-']=1;
	m['*']=m['/']=2;
	m['(']=m[')']=3;
	string s;
	cin>>s;
	int i=0,q=1;
	while(i<s.size())
	{
		if(isdigit(s[i])||((i==0)||s[i-1]=='(')&&(s[i]=='+'||s[i]=='-'))
		{
			if(q)
				q=0;
			else
				cout<<" ";
			if(s[i]=='-'||isdigit(s[i]))
				cout<<s[i];
			while(s[i+1]=='.'||isdigit(s[i+1]))
				cout<<s[++i];
			i++;
		}
		else
		{
			if(s[i]=='(')
				st.push(s[i]);
			else if(s[i]==')')
			{
				while(st.top()!='('&&!st.empty())
				{
					cout<<' '<<st.top();
					st.pop();
				}
				st.pop();//'('
			}
			else
			{
				while(!st.empty()&&st.top()!='('&&m[st.top()]>=m[s[i]])
				{
					cout<<' '<<st.top();
					st.pop();
				}
				st.push(s[i]);
			}
			i++;
		}
	}
	while(!st.empty())
	{
		cout<<' '<<st.top();
		st.pop();
	}
} 
