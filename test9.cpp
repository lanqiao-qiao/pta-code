#include <iostream>
#include <cstdio>
using namespace std;
struct duo
{
	int zhi;
	int xi;
	struct duo* next;
};
typedef struct duo* Duo;

Duo getduo();
Duo ans_duo(Duo a,Duo b);
void put_duo(Duo a);
Duo sum_duo(Duo a,Duo b);
void pushin(int a,int b,Duo *p);

int main()
{
	Duo p1,p2,pans,psum;
	p1=getduo();
	p2=getduo();
	put_duo(p1);
	put_duo(p2); 
	/*pans=ans_duo(p1,p2);
	put_duo(pans);*/
	psum=sum_duo(p1,p2);
	put_duo(psum);
}
Duo getduo()
{
	Duo head,p,t;
	int n,a,b;
 	cin>>n;
 	head=new struct duo;
 	head->next=NULL;
 	p=head;
 	while(n--)
 	{
		cin>>a>>b;
		//pushin(a,b,&p);	
		Duo q;
		q=new(duo);
		q->xi=a;
		q->zhi=b;
		q->next=NULL;
		p->next=q;
		p=q;
		cout<<p->xi<<' '<<p->zhi<<endl;
	}
	//t=head;
	head=head->next;//È¥³ýÍ·Ö¸Õë 
	//delete(t);
	cout<<head->xi<<' '<<head->zhi<<endl;
	return head;
} 
void pushin(int a,int b,Duo *p)
{
	Duo q;
	q=new(duo);
	q->xi=a;
	q->zhi=b;
	q->next=NULL;
	(*p)->next=q;
	*p=q;
	cout<<(*p)->xi<<' '<<(*p)->zhi<<endl;
}
void put_duo(Duo a)
{
	int q=0;
	if(!a)
		cout<<"0 0"<<endl;
	while(a)
	{
		//cout<<"@"<<endl;
		if(!q)
			q=1;
		else
			cout<<' ';
		cout<<a->xi<<' '<<a->zhi;
		a=a->next; 
	}
	cout<<endl;
}
Duo sum(Duo p1,Duo p2)
{
	Duo a,b,head,q,p;
	a=p1;
	b=p2;
	head=new(duo);
	head->next=NULL;
	p=head;
	while(a&&b)
	{
		if(a->xi==b->xi)
		{
			p=new(duo);
			p->xi=a->xi;
			p->zhi=a->zhi+b->zhi;
		}
		p->next=q;
		p=q;
	}
	head=head->next;
	return head;
}













