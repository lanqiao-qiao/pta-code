#include <iostream>
#include <map>
#include <vector>
using namespace std;
int main()
{
	map<int,int> m;
	m[1]=10;
	m[2]=20;
	m[3]=30;
	m[4]=40;
	m[5]=50;
	map<int,int>::iterator it;
	it=m.find(2);
	cout<<it->first<<endl;
	for(it=m.begin();it!=m.end();it++)
	{
		cout<<it->first<<' '<<it->second<<endl;
	}
	vector<int> s;
	s.push_back(1);
	vector<int>::iterator it2;
	it2=s.begin();
	cout<<*it2<<endl;
}
