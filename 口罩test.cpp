#include <iostream>
#include <cstdlib>
#include <queue>
#include <fstream>
using namespace std;
int all_n,all_n_2,last_n,people_n,all_people_n;
int c1=0,c2=0;
int pos[10000],pos_i=0,posn[10000],posn_i; 
struct people
{
	int id;
	int n;
	int p;	
}PEO[10000];
bool operator<(people a,people b)
{
	if(a.n!=b.n)
		return a.n<b.n;
	else
		return a.id>b.id;
}
priority_queue<people> p1,p2;
int ID[10000];
void load()
{
	ifstream in("people.txt", ios::in);
	char s[10],a[10],b[10];
	in.getline(s,10);
	//cout<<s<<endl;
	all_people_n=atoi(s);
	for(int i=0;i<all_people_n;i++)
	{
		in.getline(s,10);
		in.getline(a,10);
		in.getline(b,10);
		int id=atoi(s);
		PEO[id].id=id;
		PEO[id].n=atoi(a);
		PEO[id].p=atoi(b);
		//cout<<"@"<<id<<endl;
	}
}
void save()
{
	ofstream out("people.txt", ios::out);
	out.clear();
	out << all_people_n<<endl;
	for(int i=0;i<all_people_n;i++)
	{
		out<<PEO[i].id<<endl;
		out<<PEO[i].n<<endl;
		out<<PEO[i].p<<endl;
	}
}
void print()
{
	for(int i=0;i<all_people_n;i++)
	{
		cout<<PEO[i].n<<endl;
	}
}
void pop_p1()
{
	while(!p1.empty())
	{
		int id=p1.top().id;
		PEO[id].n++;
		p1.pop();
		posn[posn_i++]=id;
	}
}
void pop_p2()
{
	while(!p2.empty())
	{
		int id=p2.top().id;
		PEO[id].n++;
		p2.pop();
		posn[posn_i++]=id;
	}
}
void printinf()
{
	cout<<"本次计划放送口罩共 "<<all_n_2<<endl;
	cout<<"实际送出口罩共 "<<pos_i<<"人/份"<<endl;
	cout<<"送出人id如下:"<<endl;
	for(int i=0;i<pos_i;i++)
		cout<<pos[i]<<' ';
	cout<<endl; 
	if(posn_i!=0)
	{
		cout<<"预约但未收到的人id如下"<<endl;
		for(int i=0;i<posn_i;i++)
			cout<<posn[i]<<' ';
		cout<<endl;
	}
}
int main()
{
	load();
	//print();
	//cout<<all_people_n;
	cout<<"请输入本次放送口罩总数"<<endl;
	cin>>all_n;
	all_n_2=all_n;
	cout<<"请输入口罩放送保险值"<<endl;
	cin>>last_n;
	cout<<"请输入本次申请的人数"<<endl;
	cin>>people_n;
	cout<<"请按顺序输入申请人的id"<<endl;
	for(int i=0;i<people_n;i++)
		cin>>ID[i];
	for(int i=0;i<people_n;i++)
	{
		if(PEO[ID[i]].p==0)
			p1.push(PEO[ID[i]]);
		else
			p2.push(PEO[ID[i]]);	
	} 
	//cout<<"???"<<endl;
	while(!p1.empty())
	{
		if(all_n==0)
		{
			c1=1;
			break;
		}
		int id=p1.top().id;
		//cout<<"#"<<id<<endl;
		pos[pos_i++]=id;
		//cout<<p1.front().id<<endl;
		PEO[id].p=1;
		PEO[id].n=0;
		p1.pop();
		all_n--;
	}
	if(c1==1)
	{
		cout<<"口罩已用完"<<endl;
		pop_p1();
		pop_p2();
		//printinf();
	}
	else if(all_n<=last_n)
	{
		cout<<"到达控制值，暂停发放"<<endl;
		pop_p2();	
		//printinf();
	} 
	else
	{
		while(!p2.empty())
		{
			if(all_n==0)
			{
				c1=2;
				break;
			}
			if(all_n<=last_n)
			{
				c2=1;
				break;
			}
			int id=p2.top().id;
			pos[pos_i++]=id;
			PEO[id].p=1;
			PEO[id].n=0;
			p2.pop();
			all_n--;
		}
		if(c1==2)
		{
			cout<<"口罩已经用完"<<endl;
			//pop_p1();
			pop_p2();
		//	printinf();
		}
		else if(c2==1)
		{
			cout<<"到达了控制值，暂停发放"<<endl;
			pop_p2();
			//printinf();
		} 
	}
	printinf();
	save();		
}

