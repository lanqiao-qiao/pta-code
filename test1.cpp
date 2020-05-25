#include <iostream>
using namespace std;
struct stu
{
	int n;
	struct stu *next;	
};
stu *head;
stu *q,*p;
void add(int n);
void del(int n);
void print();
void insert(int X);
int main()
{
	head=new stu;
	head=NULL;
	add(1);
	add(2);
	print();
	add(3);
	print();
	del(2);
	insert(0);
	print();
	
}
void add(int n)
{
	p=new stu;
	p->n=n;
	p->next=NULL;
	if(head==NULL)
	{
		head=p;	
		q=head;
	}
	else
	{
		q=head;
		while(q->next)
		{
			q=q->next;
		}
		q->next=p;
		q=q->next;
	}
}
void print()
{
	q=head;
	while(q)
	{
		cout<<q->n<<" ";
		q=q->next;
	}
	cout<<endl;
}
void del(int n)
{
	q=head;
	while(q)
	{
		if(q->next->n==n)
			break;
		else
			q=q->next;
	}
	cout<<q->n<<endl;
	q->next=q->next->next;
}//头指针也存储信息（存储第一项）
void insert(int X )
{
	stu *p=head,*s,*left=p;
	s=new stu;
	if(p->n>X)
	{
		s->n=X;
		s->next=p;
		head=s;
	}
	else
	{
		while(p)
		{
			if(p->n>X)
				break;
			left=p;
			p=p->next;
		}
		s->n=X;
		s->next=left->next;
		left->next=s;
	}
} /*
void insert(int X)
{
	stu *p=head,*s,*left=p;
	s=new stu;
	while(p)
	{
		if(p->n>X)
			break;
		left=p;
		p=p->next;
	}
	s->n=X;
	s->next=left->next;
	left->next=s;
} */
