#include <iostream>
#include <cstdlib>
#include <queue>
#include <fstream>
using namespace std;
struct people
{
	int id;
	int n;
	int p;
}a[10000];
bool operator<(people a,people b)
{
	return a.n<b.n;
}
int main()
{
	/*priority_queue<people> p;
	a[0].id=1;
	a[0].n=2;
	a[0].p=0;
	a[1].id=2;
	a[1].n=1;
	a[1].p=0;
	a[2].id=3;
	a[2].n=3;
	a[2].p=0;
	p.push(a[0]);
	p.push(a[1]);
	p.push(a[2]);
	people b;
	for(int i=0;i<3;i++)
	{
		cout<<p.top().id<<endl;	
		p.pop();
	}*/
	for(int i=0;i<100;i++)
	{
		cout<<i<<endl;
		cout<<0<<endl;
		cout<<0<<endl;	
	}	
}
