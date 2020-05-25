#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 20
typedef int ElementType;

typedef int Position;
typedef struct LNode *List;
struct LNode 
{
    ElementType Data[MAXSIZE];
    Position Last; /* 保存线性表中最后一个元素的位置 */
};

List ReadInput(); /* 裁判实现，细节不表。元素从下标0开始存储 */
void PrintList( List L ); /* 裁判实现，细节不表 */
List Delete( List L, ElementType minD, ElementType maxD );

int main()
{
    List L;
    ElementType minD, maxD;
    int i;

    L = ReadInput();
    scanf("%d %d", &minD, &maxD);
    L = Delete( L, minD, maxD );
    PrintList( L );

    return 0;
}
List ReadInput()
{
	List s;
	s=(List)malloc(sizeof(LNode));
	int n;
	scanf("%d",&n);
	s->Last=n-1;
	for(int i=0;i<n;i++)
	{
		scanf("%d",&s->Data[i]);
	}
	return s;
} 
List Delete( List L, ElementType minD, ElementType maxD )
{
	int i,p=0;
	for(int i=0;i<=L->Last;i++)
	{
		if(L->Data[i]>minD&&L->Data[i]<maxD)
			p++;
		else
			L->Data[i-p]=L->Data[i];
	}
	L->Last-=p;
	return L;
} 
void PrintList( List L )
{
	for(int i=0;i<=L->Last;i++)
		printf("%d ",L->Data[i]);
}
