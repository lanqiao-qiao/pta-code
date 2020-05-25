#include <iostream>
#include <sstream>
#include <cstdlib> 
using namespace std;
void han6()
{
	double n1,n2,n3,n4;
	double sum;
	n1=rand()%11;
	n2=rand()%9+1;
	n3=rand()%11;
	n4=rand()%9+1;
	if(n1==n3)
	{
		if(n2<n4)
		{
			int k=n2;
			n2=n4;
			n4=k;
		}
	}
	else if(n1<n3)
	{
		int k=n1;
		n1=n3;
		n3=k;
	}
	//cout<<n1<<'.'<<n2<<' '<<n3<<'.'<<n4<<endl;
	stringstream s1,s2,s3,s4;
	s1<<n1;
	s2<<n2;
	s3<<n3;
	s4<<n4;
	sum=n1-n3+n2/10-n4/10;
	//dq[dj++]=sum;
	string sa,sb,sc,sd;
	sa=s1.str();
	sb=s2.str();
	sc=s3.str();
	sd=s4.str();
	string c=sa+'.'+sb+'-'+sc+'.'+sd+'=';
	//for(int i=c.length();i<=20;i++)
	//	c+=' ';
	cout<<c;
	cout<<sum<<endl;
} 
int main()
{
for(int i=0;i<100;i++)
{
	srand(i);
	han6();
	cout<<endl;
}
}
