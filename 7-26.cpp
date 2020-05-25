#include <iostream>
#include <algorithm>
using namespace std;
struct student
{
	int a;
	string id;
	int p;
	int kp;
};
student s[30050];
bool cmp(student x,student y)
{
	if(x.p!=y.p)
		return x.p>y.p;
	else
		return x.id<y.id;
}
int main()
{
	int n,k,q=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		student sk[500]; 
		cin>>k;
		for(int j=0;j<k;j++)
		{
			cin>>sk[j].id>>sk[j].p;
		}
		sort(sk,sk+k,cmp);
		for(int j=0;j<k;j++)
		{
			s[q]=sk[j];
			s[q].a=i;
			if(j&&sk[j].p==sk[j-1].p) 
				s[q].kp=s[q-1].kp;
			else
				s[q].kp=j;
			q++;
		}
	}
	sort(s,s+q,cmp);
	int b=0;
	cout<<q<<endl;
	for(int i=0;i<q;i++)
	{
		if(i&&s[i].p==s[i-1].p)
			b=b;
		else
			b=i;
		cout<<s[i].id<<' '<<b+1<<' '<<s[i].a<<' '<<s[i].kp+1<<endl;
	}
}
