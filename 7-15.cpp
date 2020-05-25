#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;
stack<int> s;
struct node 
{
	int to;
	int pri;
};
vector<node> mis[105];
int in[105];//»Î∂»
int dis[105];
int p=0;
void tuopu()
{
	while(s.size())
	{
		int a=s.top();
		s.pop();
		p++;
		for(int i=0;i<mis[a].size();i++)
		{
			int bto=mis[a][i].to;
			int bpri=mis[a][i].pri;
			in[bto]--;
			if(in[bto]==0)
				s.push(bto);
			dis[bto]=max(dis[bto],dis[a]+bpri);
		}
	}
}
int main()
{
	int n,m;
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		int a,b,c;
		cin>>a>>b>>c;
		node d;
		d.to=b;
		d.pri=c;
		mis[a].push_back(d);
		in[b]++;
	}
	for(int i=0;i<n;i++)
	{
		if(in[i]==0)
			s.push(i);
	}
	tuopu();
	int maxx=0;
	for(int i=0;i<n;i++)
		maxx=max(maxx,dis[i]);
	if(p==n)
		cout<<maxx<<endl;
	else
		cout<<"Impossible"<<endl;
}
