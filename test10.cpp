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
	//put_duo(p1);
	//put_duo(p2); 
	pans=ans_duo(p1,p2);
	put_duo(pans);
	psum=sum_duo(p1,p2);
	put_duo(psum);
	//cout<<psum->xi<<psum->zhi<<endl;
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
		//cout<<p->xi<<' '<<p->zhi<<endl;
	}
	//t=head;
	head=head->next;//È¥³ýÍ·Ö¸Õë 
	//delete(t);
	//cout<<head->xi<<' '<<head->zhi<<endl;
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
void put_duo(Duo aa)
{
	Duo a=aa;
	int q=0,qq=0;
	if(!a)
		cout<<"0 0"<<endl;
	while(a)
	{
		//cout<<"@"<<endl;
		if(a->xi)
		{
			qq=1;
			if(!q)
				q=1;
			else
				cout<<' ';
			cout<<a->xi<<' '<<a->zhi;
			//a=a->next; 
		}
		a=a->next; 
		if(qq==0)
			cout<<"0 0"<<endl;
	}
	cout<<endl;
}
Duo sum_duo(Duo p1,Duo p2)
{
	Duo a,b,head,q,p;
	a=p1;
	b=p2;
	head=new(duo);
	head->next=NULL;
	p=head;
	while(a&&b)
	{
		//cout<<"@"<<endl;
		if(a->zhi==b->zhi)
		{
			//cout<<"@"<<endl;
			q=new(duo);
			q->zhi=a->zhi;
			q->xi=a->xi+b->xi;
			q->next=NULL; 
			p->next=q;
			p=q;
			a=a->next;
			b=b->next;
		}
		else if(a->zhi>b->zhi)
		{
			q=new(duo);
			q->zhi=a->zhi;
			q->xi=a->xi;
			q->next=NULL; 
			p->next=q;
			p=q;
			a=a->next;
		}
		else
		{
			q=new(duo);
			q->zhi=b->zhi;
			q->xi=b->xi;
			q->next=NULL; 
			p->next=q;
			p=q;
			b=b->next;
		}
		if(a)
		{
			p->next=a;
		}
		if(b)
		{
			p->next=b;
		}
	}
	head=head->next;
	return head;
}
Duo ans_duo(Duo p1,Duo p2)
{
	if(!p1||!p2)
		return NULL;
	Duo a,b,head,q,p,t;
	a=p1;
	b=p2;
	head=new(duo);
	head->next=NULL;
	p=head;
	while(b)
	{
		//cout<<"@"<<endl;
		q=new(duo);
		q->zhi=a->zhi+b->zhi;
		q->xi=a->xi*b->xi;
		q->next=NULL; 
		p->next=q;
		p=q;
		b=b->next;
	}
	a=a->next;
	while(a)
	{
		b=p2;
		p=head;
		while(b)
		{
			//cout<<"@"<<endl;
			int z=a->zhi+b->zhi;
			int x=a->xi*b->xi;
			while(p->next&&p->next->zhi>z)
				p=p->next;
			if(p->next&&p->next->zhi==z)
			{
				if(p->next->xi+x)
					p->next->xi+=x;
				else
				{
					t=p->next;
					p->next=t->next;
					delete(t);
				}
			}
			else
			{
				q=new(duo);
				q->xi=x;
				q->zhi=z;
				q->next=p->next;
				p->next=q;
				p=p->next;
			}
			b=b->next;
		}
		a=a->next;
	}
	head=head->next;
	return head;
}


















