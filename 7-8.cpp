#include <iostream>
#include <map>
using namespace std;
struct tree
{
	char ch;
	int left;
	int right;
};
typedef tree *tnode;
int main()
{
	tree t1[10050],t2[10050];
	map<char,int> M;
	int nt1,nt2;
	cin>>nt1;
	for(int i=0;i<nt1;i++)
	{
		char a[10],b[10];
		cin>>t1[i].ch>>a>>b;
		M[t1[i].ch]=i;
		//cout<<a<<" "<<b<<"@"<<endl;
		//char a[10],b[10];
		if(a[0]!='-')
			t1[i].left=a[0]-'0';
		else
			t1[i].left=-1;
		if(b[0]!='-')
			t1[i].right=b[0]-'0';
		else
			t1[i].right=-1;	
	}
	/*for(int i=0;i<nt1;i++)
	{
		cout<<t1[i].ch<<' '<<t1[i].left<<' '<<t1[i].right<<endl;
	}*/
	cin>>nt2;
	for(int i=0;i<nt2;i++)
	{
		char a[10],b[10];
		cin>>t2[i].ch>>a>>b;
		//M[t2[i].ch]=i;
		//cout<<a<<" "<<b<<"@"<<endl;
		//char a[10],b[10];
		if(a[0]!='-')
			t2[i].left=a[0]-'0';
		else
			t2[i].left=-1;
		if(b[0]!='-')
			t2[i].right=b[0]-'0';
		else
			t2[i].right=-1;	
	}
	/*for(int i=0;i<nt1;i++)
	{
		cout<<M[t2[i].ch]<<endl;
	}*/
	if(nt1!=nt2)
	{
		cout<<"No"<<endl;
	}
	else
	{
		int q=0;
		for(int i=0;i<nt2;i++)
		{
			int j=M[t2[i].ch];
			if(t1[j].ch!=t2[i].ch)
			{
				q=1;
				break;
			}
			char a1,b1,a2,b2;
			a1=t1[t1[j].left].ch;
			b1=t1[t1[j].right].ch;
			a2=t2[t2[i].left].ch;
			b2=t2[t2[i].right].ch;
			if((a1==a2&&b1==b2)||(a1==b2&&a2==b1))
			{
				q=0;
			}
			else
			{
				//cout<<i<<endl;
				//cout<<a1<<' '<<a2<<' '<<b1<<' '<<b2<<endl;
				q=1;
				break;
			}
		}
		if(q==0)
			cout<<"Yes"<<endl;
		else
			cout<<"No"<<endl;
	}
}
/*
3
A 1 -
B - 2
C - -
3
A - 1
B 2 -
C - -
*/
