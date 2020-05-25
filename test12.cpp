#include <iostream>
#include <stdio.h>
#include <cstring>
#include <cstdlib>
#define N 1000

using namespace std;

typedef struct nodes{
	int a;	//系数 
	int b;	//指数 
	struct nodes *next;	//指向下一个节点 
}*sktlist,skt;  
sktlist p1,p2,p3;
sktlist head1,rear1;
sktlist head2,rear2;
int p=0;//判断是否进行了运算 
/*函数头*/ 
int initlist();
void display(); //交互式界面 
void shuru();//输入函数 
void shuchu();//输出函数 
void attach(int x,int y,sktlist *rear);
void nodesadd();//多项式加法
void nodessub();//多项式减法
void nodesmul();//多项式乘法

int main()
{
	initlist();
	head1=rear1;
	head2=rear2;
	display();
	return 0;
}
void display()
{
	cout<<"请选择运算方式(输入对应数字即可)："<<endl;
	cout<<"1.相加"<<endl;
	cout<<"2.相减"<<endl;
	cout<<"3.相乘"<<endl;
	cout<<"4.输出"<<endl;
	int n;
	cin>>n;
	switch(n){
		case 1:
			shuru();
			nodesadd();
			break;
		case 2:
			shuru();
			nodessub();
			break;
		case 3:
			shuru();
			nodesmul();
			break;
		case 4:
			shuchu();
			break;
	}
}
int initlist()
{
	p1=new skt;
	p2=new skt;
	p3=new skt;
	p1->next=NULL;
	p2->next=NULL;
	p3->next=NULL;
	rear1=p1;
	rear2=p2;
	return 1;
}
void shuru()
{
	sktlist r,temp;
	r=rear1;
	int x,y;
	cout<<"请输入第一个多项式各项的系数和指数(输入'0 0'表示输入结束):"<<endl;
	while(1)
	{
		cin>>x>>y;
		if(!x && !y)
			break;
		sktlist temp=new skt;
		temp->a=x;
		temp->b=y;
		temp->next=NULL;
		r->next=temp;
		r=temp;
	}
	rear1=r;
	p1=head1->next;
	/*while(p1!=NULL)
	{
		cout<<p1->a<<' '<<p1->b;
		p1=p1->next;
	}*/
	sktlist rr;
	rr=rear2;
	cout<<"请输入第二个多项式各项的系数和指数(输入'0 0'表示输入结束):"<<endl;
	while(1)
	{
		cin>>x>>y;
		if(!x && !y)
			break;
		sktlist temp=new skt;
		temp->a=x;
		temp->b=y;
		temp->next=NULL;
		rr->next=temp;
		rr=temp;
	}
	rear2=rr;
	p2=head2->next;
	/*while(p2!=NULL)
	{
		cout<<p2->a<<' '<<p2->b;
		p2=p2->next;
	}*/
}
void shuchu()
{
	if(p==0)
		cout<<"error:未进行运算"<<endl;
	else
	{
		while(p3)
		{
			if(p3->b==0)
				cout<<p3->a;
			else
			{
				if(!p3->next)
				{
					if(p3->a==1)
					{
						if(p3->b==1)
							cout<<'x';
						else
							cout<<'x'<<'^'<<p3->b;
					}
					else
					{
						if(p3->b==1)
							cout<<p3->a<<'x';
						else
							cout<<p3->a<<'x'<<'^'<<p3->b;
					}
				}
				else
				{
					if(p3->next->a>=0)
					{
						if(p3->a==1)
						{
							if(p3->b==1)
								cout<<'x'<<'+';
							else
								cout<<'x'<<'^'<<p3->b<<'+';
						}
						else
						{
							if(p3->b==1)
								cout<<p3->a<<'x'<<'+';
							else
								cout<<p3->a<<'x'<<'^'<<p3->b<<'+';
						}
					}
					else
					{
						if(p3->a==1)
						{
							if(p3->b==1)
								cout<<'x';
							else
								cout<<'x'<<'^'<<p3->b;
						}
						else
						{
							if(p3->b==1)
								cout<<p3->a<<'x';
							else
								cout<<p3->a<<'x'<<'^'<<p3->b;
						}
					}
				}
			}
			p3=p3->next;
		}
		cout<<endl;
	}
	display();
}
void attach(int x,int y,sktlist *rear)
{
	sktlist t;
	t=(sktlist)malloc(sizeof(struct nodes));
	t->a=x;
	t->b=y;
	t->next=NULL;
	(*rear)->next=t;
	*rear=t;
}
void nodesadd()
{
	//initlist();
	p=1;
	sktlist head,rear;
	int sum;
	rear=(sktlist)malloc(sizeof(struct nodes));
	head=rear;
	while(p1 && p2) 
	{
		int pp;
		if(p1->b==p2->b)
			pp=0;
		else if(p1->b>p2->b)
			pp=1;
		else if(p1->b<p2->b)
			pp=-1;
		//cout<<pp<<endl;
		switch(pp){
			case 0:
				sum=p1->a+p2->a;
				if(sum!=0)
					attach(sum,p1->b,&rear);
				p1=p1->next;
				p2=p2->next;
				break;
			case 1:
				attach(p1->a,p1->b,&rear);
				p1=p1->next;
				break;
			case -1:
				attach(p2->a,p2->b,&rear);
				p2=p2->next;
				break;
		}
	}
	while(p1)
	{
		attach(p1->a,p1->b,&rear);
		p1=p1->next;
	}
	while(p2)
	{
		attach(p2->a,p2->b,&rear);
		p2=p2->next;
	}
	rear->next=NULL;
	//temp=head;
	head=head->next;
	p3=head;
	//free(temp);
	display();
}
void nodessub()
{
	//initlist();
	p=1;
	sktlist head,rear;
	int sum;
	rear=(sktlist)malloc(sizeof(struct nodes));
	head=rear;
	while(p1 && p2) 
	{
		int pp;
		if(p1->b==p2->b)
			pp=0;
		else if(p1->b>p2->b)
			pp=1;
		else if(p1->b<p2->b)
			pp=-1;
		//cout<<pp<<endl;
		switch(pp){
			case 0:
				sum=p1->a-p2->a;
				if(sum!=0)
					attach(sum,p1->b,&rear);
				p1=p1->next;
				p2=p2->next;
				break;
			case 1:
				attach(p1->a,p1->b,&rear);
				p1=p1->next;
				break;
			case -1:
				attach((-1)*p2->a,p2->b,&rear);
				p2=p2->next;
				break;
		}
	}
	while(p1)
	{
		attach(p1->a,p1->b,&rear);
		p1=p1->next;
	}
	while(p2)
	{
		attach(p2->a,p2->b,&rear);
		p2=p2->next;
	}
	rear->next=NULL;
	//temp=head;
	head=head->next;
	p3=head;
	//free(temp);
	display();
}
void nodesmul()
{
	//initlist();
	p=1;
	sktlist head,rear,temp,t1,t2,q;
	int sum,sum1,sum2;
	//rear=(sktlist)malloc(sizeof(struct nodes));
	//head=rear;
	t1=p1;
	t2=p2;
	q=(sktlist)malloc(sizeof(struct nodes));
	q->next=NULL;
	rear=q;
	//head=rear;
	while(t2)
	{
		attach(t1->a*t2->a,t1->b+t2->b,&rear);
		t2=t2->next;
	}
	t1=t1->next;
	while(t1)
	{
		//cout<<'1'<<endl;
		t2=p2;
		rear=q;
		while(t2)
		{
			//cout<<'0'<<endl;//
			sum1=t1->a*t2->a;
			sum2=t1->b+t2->b;
			//cout<<rear->a<<endl;//
			while(rear->next && rear->next->b>sum2)
				rear=rear->next;
			if(rear->next &&rear->next->b==sum2)
			{
				sum=rear->next->a+sum1;
				if(sum)
					rear->next->a=sum;
				else
				{
					temp=rear->next;
					rear->next=temp->next;
					free(temp);
				}
			}
			else
			{
				temp=(sktlist)malloc(sizeof(struct nodes));
				temp->a=sum1;
				temp->b=sum2;
				temp->next=rear->next;
				rear->next=temp;
				rear=rear->next;
			}
			t2=t2->next;
		}
		t1=t1->next;
	}
	t2=q;
	q=q->next;
	free(t2);
	//rear->next=NULL;
	//temp=head;
	//head=head->next;
	p3=q;
	//free(temp);
	//sktlist a1,a2;
	/*while(p3)
	{
		a1=p3;
		a2=p3->next;
		if(a1->b==a2->b)
		{
			sum=a1->a+a2->a;
			a1->a=sum;
			temp=p3->next;
			p3->next=temp->next;
		}
		p3=p3->next;
	}*/
	//free(temp);
	display();
}
