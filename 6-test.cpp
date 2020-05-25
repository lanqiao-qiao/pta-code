#include <iostream>
using namespace std;
struct stu
{
	int n;
	struct stu* next;
};
stu* q, * p;
void add(int n,stu* head);
void del(int n,stu* head);
void print(stu* head);
stu* Merge(stu* L1, stu* L2 );
int main()
{
	stu *h1=new stu;
	stu *h2=new stu;
	stu *h3=new stu;
	h1->next = NULL;
	h2->next=NULL;
	add(1,h1);
	add(3,h1);
	add(2,h2);
	add(4,h2);
	print(h1);
	print(h2);
	h3=Merge(h1,h2);
	print(h3);
	print(h1);
	print(h2);
}
void add(int n,stu* head)
{
	p = new stu;
	p->n = n;
	p->next = NULL;
	if (head->next == NULL)
	{
		head->next = p;
	}
	else
	{
		q = head->next;
		while (q->next)
		{
			q = q->next;
		}
		q->next = p;
		q = q->next;
	}
}
void print(stu* head)
{
	q = head->next;
	while (q)
	{
		cout << q->n << " ";
		q = q->next;
	}
	cout << endl;
}
stu* Merge(stu* a, stu* b )
{
	stu* L,*L1,*L2;
	stu* LY=new stu;
	L=LY;
	L1=a->next;
	L2=b->next;
	while(L1&&L2)
	{
		if(L1->n<=L2->n)
		{
			L->next=L1;
			L=L1;
			L1=L1->next;
		}
		else
		{
			L->next=L2;
			L=L2;
			L2=L2->next;
		}
	}
	if(L1)
	{
		L->next=L1;
		a->next=NULL;
		b->next=NULL;
	}
	else
	{
		L->next=L2;
		a->next=NULL;
		b->next=NULL;
	}
	return LY;
}
