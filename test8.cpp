#include <iostream>
#define MAXSIZE 100
using namespace std;
typedef int ElemType;
typedef int Status;

struct SqStack
{
	ElemType *base;
	ElemType *top;
	int stacksize;	
};
Status InitStack(SqStack &S)
{
	cout<<"#"<<endl;
	S.base=new ElemType[MAXSIZE];
	cout<<"&"<<endl;
	if(!S.base) 
	{
		cout<<"&"<<endl;
		exit(0);
	}
	cout<<"()"<<endl;
	S.top=S.base;
	S.stacksize=MAXSIZE;
	return 1;
}
Status Push(SqStack &S,ElemType e)
{
	cout<<"@"<<endl;
	if(S.top-S.base==S.stacksize)
	return 0;
	*S.top++=e;
	return 1;
}
Status Pop(SqStack &S,ElemType e)
{
	if(S.top==S.base)
	return 0;
	e=*--S.top;
	return 1;
}
ElemType GetTop(SqStack S,ElemType e)
{
	if(S.top!=S.base)
	e=*(S.top-1);
	return e;
}
void StackTraverse(SqStack S)
{
	ElemType *p;
	p=S.base;
	while(p!=S.top)
	{
		cout<<*p++<<' ';
	}
	cout<<endl;
}
int StackLength(SqStack S)
{
	int count=S.top-S.base;
	return count;
}
int main()
{
	SqStack S;
	ElemType e;
	InitStack(S);
	Push(S,2);
	Push(S,4);
	Push(S,6);
	Push(S,8);
	cout<<"\n由栈底至栈顶的元素为：";
	StackTraverse(S);
	cout<<"\n栈的长度为："<<StackLength(S)<<endl;
	GetTop(S,e);
	cout<<"\n栈顶元素为："<<e<<endl;
	Pop(S,e);
	cout<<"\n由栈底至栈顶的元素为：";
	StackTraverse(S);
	cout<<"\n栈的长度为："<<StackLength(S)<<endl;
	GetTop(S,e);
	cout<<"\n栈顶元素为："<<e<<endl;	
}
