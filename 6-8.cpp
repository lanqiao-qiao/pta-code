#include <stdio.h>
#include <stdlib.h>

#define ERROR -1
typedef int ElementType;

typedef int Position;
typedef struct QNode *PtrToQNode;
struct QNode {
    ElementType *Data;      /* 存储元素的数组   */
    Position Front, Rear;   /* 队列的头、尾指针 */
    int MaxSize;            /* 队列最大容量     */
};
typedef PtrToQNode Deque; 

Deque CreateDeque( int MaxSize )
{   /* 注意：为区分空队列和满队列，需要多开辟一个空间 */
    Deque D = (Deque)malloc(sizeof(struct QNode));
    MaxSize++;
    D->Data = (ElementType *)malloc(MaxSize * sizeof(ElementType));
    D->Front = D->Rear = 0;
    D->MaxSize = MaxSize;
    return D;
}
ElementType Pop(Deque D)
{
	if(D->Rear==D->Front)
		return ERROR;
	else
	{
		int a=D->Data[D->Front];
		D->Front=(D->Front+1)%D->MaxSize;
		return a;
	}
	
}
ElementType Eject(Deque D)
{
	if(D->Rear==D->Front)
		return ERROR;
	else
	{
		D->Rear = (D->Rear -1 +D->MaxSize)%D->MaxSize;
		int a=D->Data[D->Rear];
		return a;
	}
	
}
bool Push(ElementType X,Deque D)
{
	if((D->Rear+1)%(D->MaxSize)==D->Front)
	{
		return false; 
	}
	else
	{
		D->Front=(D->Front-1+D->MaxSize)%D->MaxSize;
		D->Data[D->Front]=X;
		return true;
	}
}
bool Inject(ElementType X, Deque D)
{
	if((D->Rear+1)%(D->MaxSize)==D->Front)
		return false;
	else
	{
		D->Data[D->Rear]=X;
		D->Rear=(D->Rear+1)%D->MaxSize;
		return true;
	}
}

int main()
{
	int n;
}












