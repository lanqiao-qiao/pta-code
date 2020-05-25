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
}
//头指针也存储信息（存储第一项）
/*
//第一项只做指针用
#include <iostream>
using namespace std;
struct stu
{
	int n;
	struct stu* next;
};
stu* head=new stu;
stu* q, * p;
void add(int n);
void del(int n);
void print();
int main()
{
	head->next = NULL;
	add(1);
	add(2);
	print();
	add(3);
	print();
	del(2);
	print();
}
void add(int n)
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
void print()
{
	q = head->next;
	while (q)
	{
		cout << q->n << " ";
		q = q->next;
	}
	cout << endl;
}
void del(int n)
{
	q = head->next;
	while (q)
	{
		if (q->next->n == n)
			break;
		else
			q = q->next;
	}
	cout << q->n << endl;
	q->next = q->next->next;
}
*/
