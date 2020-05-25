#include <stdio.h>
#include <stdlib.h>

typedef char ElementType;
typedef struct TNode *Position;
typedef Position BinTree;
struct TNode{
    ElementType Data;
    BinTree Left;
    BinTree Right;
};

BinTree CreatBinTree(); /* ?????? */
void InorderTraversal( BinTree BT );//bac 
void PreorderTraversal( BinTree BT );
void PostorderTraversal( BinTree BT );
void LevelorderTraversal( BinTree BT );

int main()
{
    BinTree BT = CreatBinTree();
    printf("Inorder:");    InorderTraversal(BT);    printf("\n");
    printf("Preorder:");   PreorderTraversal(BT);   printf("\n");
    printf("Postorder:");  PostorderTraversal(BT);  printf("\n");
    printf("Levelorder:"); LevelorderTraversal(BT); printf("\n");
    return 0;
}
void InorderTraversal( BinTree BT )
{
	if(BT)
	{
		InorderTraversal(BT->Left);
		printf(" %c",BT->Data);
		InorderTraversal(BT->Right);
	}
}
void PreorderTraversal( BinTree BT )
{
	if(BT)
	{
		printf(" %c",BT->Data);
		PreorderTraversal(BT->Left);
		PreorderTraversal(BT->Right);
	}
}
void PostorderTraversal( BinTree BT )
{
	if(BT)
	{
		PostorderTraversal(BT->Left);
		PostorderTraversal(BT->Right);
		printf(" %c",BT->Data);
	}
}
void LevelorderTraversal( BinTree BT )
{
	BinTree que[1050];
	BinTree q;
	int l=0,r=0;
	if(!BT)
		return;
	else
	{
		que[r++]=BT;//入队
		while(l<r)
		{
			q=que[l];
			printf(" %c",q->Data);
			l++;//出队
			if(q->Left)
				que[r++]=q->Left;
			if(q->Right)
				que[r++]=q->Right;	
		} 
	}
}










