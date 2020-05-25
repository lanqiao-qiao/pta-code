#include <iostream>
#include <cstdio>
#include <algorithm> 
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
Duo del_duo(Duo p1,Duo p2);//减法 
void pushin(int a,int b,Duo *p);
int cmp(duo a,duo b)
{
	return a.xi>b.xi;
} 
int main()
{
	Duo p1,p2,pans,psum,pdel;
	cout<<"输入两个多项式"<<endl;
	p1=getduo();
	p2=getduo();
	//put_duo(p1);
	//put_duo(p2); 
	pans=ans_duo(p1,p2);
	cout<<'\n'<<"多项式的积"<<endl;
	put_duo(pans);
	psum=sum_duo(p1,p2);
	cout<<'\n'<<"多项式的和"<<endl;
	put_duo(psum);
	pdel=del_duo(p1,p2);
	cout<<'\n'<<"多项式的差"<<endl;
	put_duo(pdel); 
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
 	duo x[1005];
 	for(int i=0;i<n;i++)
 	{
 		cin>>x[i].xi>>x[i].zhi;
	}
	sort(x,x+n,cmp);
	for(int i=0;i<n;i++)
 	{
		//pushin(a,b,&p);	
		Duo q;
		q=new(duo);
		q->xi=x[i].xi;
		q->zhi=x[i].zhi; 
		q->next=NULL;
		p->next=q;
		p=q;
		//cout<<p->xi<<' '<<p->zhi<<endl;
	}
	//t=head;
	head=head->next;//去除头指针 
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
	int x1[1005],x2[1005],k=0; 
	Duo a=aa;
	int q=0,qq=0;
	if(!a)
		cout<<"0 0"<<endl;
	while(a)
	{
		//cout<<"@"<<endl;
		if(a->xi)
		{
			x1[k]=a->xi;
			x2[k]=a->zhi;
			k++;
			//a=a->next; 
		}
		a=a->next; 
	}
	cout<<"幂降序输出:  "<<endl;
	for(int i=0;i<k;i++)
	{
		if(q==1)
			cout<<" + ";
		else
			q=1; 
		if(x1[k]==1)
		{
			cout<<"x^"<<x2[i];
		}
		else
		{
			cout<<x1[i]<<"x^"<<x2[i]; 
		}
	}
	cout<<endl;
	q=0;
	cout<<"幂升序输出:  "<<endl;
	for(int i=k-1;i>=0;i--)
	{
		if(q==1)
			cout<<'+';
		else
			q=1; 
		if(x1[k]==1)
		{
			cout<<"x^"<<x2[i];
		}
		else
		{
			cout<<x1[i]<<"x^"<<x2[i]; 
		}
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
Duo del_duo(Duo p1,Duo p2)
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
			q->xi=a->xi-b->xi;
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
					//t=p->next;
					p->next=p->next->next;
					//delete(t);
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
/*
4 3 4 -5 2 -2 0  6 1 
3 3 1 5 20  -7 4
*/
