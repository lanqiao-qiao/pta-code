#include <iostream>
#include <stack>
using namespace std; 
void print(stack<int> a,stack<int> b,stack<int> c)
{
	stack <int> ae=a,be=b,ce=c;
	int as=ae.size(),bs=be.size(),cs=ce.size();
	for(int i=1;i<=4;i++)
	{
		if(as>=i)
		{
			cout<<ae.top()<<"		"; 
			ae.pop();
		}
		if(bs>=i)
		{
			cout<<be.top()<<"		"; 
			be.pop();
		}
		if(cs>=i)
		{
			cout<<ce.top(); 
			ce.pop();
		}
		cout<<endl;
	}
}
void move(stack<int> *x,stack<int> *y)
{
	//cout<<"@"<<endl;
	int m;
	m=x->top();
	//cout<<"@"<<endl;
	x->pop();
	y->push(m);
	//print(a,b,c);
	//cout<<y->top()<<endl;
}
void hanoi(int n,stack<int> *a,stack<int> *b,stack<int> *c)
{
	if(n==1)
	{
		move(a,c);
	}
	else
	{
		n--;
		hanoi(n,a,c,b);
		move(a,c);
		hanoi(n,b,a,c);
	}
	cout<<"#";
	print(*a,*b,*c);
	cout<<"#"<<endl;
}
int main()
{
	stack <int> a,b,c;
	stack <int> *x=&a,*y=&b,*z=&c;
	a.push(4);
	a.push(3);
	a.push(2);
	a.push(1);
	//move(x,y);
	//move(x,z);
	hanoi(3,x,y,z);
	print(a,b,c);
}
