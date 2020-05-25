#include <iostream>
#include <vector>
using namespace std;
struct tree
{
	char l;
	char r;
}t[15];
int tp[15];
vector<int> leaf[15];//队列也可，应用STL 
void savetree(int rt,int q)
{
	if(t[rt].l=='-'&&t[rt].r=='-')
	{
		//cout<<q<<' '<<rt<<endl;
		leaf[q].push_back(rt);
		return; 
	}
	if(t[rt].l!='-')
		savetree(t[rt].l-'0',q+1);
	if(t[rt].r!='-')
		savetree(t[rt].r-'0',q+1);
}
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>t[i].l>>t[i].r;
		if(t[i].l>='0'&&t[i].l<='9')
			tp[t[i].l-'0']=1;
		if(t[i].r>='0'&&t[i].r<='9')
			tp[t[i].r-'0']=1;
	}
	int rt;
	for(int i=0;i<n;i++)
	{
		if(tp[i]==0)
		{
			rt=i;
			break;	
		}
	}
	int q=0;
	savetree(rt,0);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<leaf[i].size();j++)
		{
			//cout<<"#"<<endl;
			if(q)
				cout<<' ';
			else
				q=1;
			cout<<leaf[i][j];
		}
	}
	cout<<endl;
}
