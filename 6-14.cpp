#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct TNode *Position;
typedef Position BinTree;
struct TNode{
    ElementType Data;
    BinTree Left;
    BinTree Right;
};

void PreorderTraversal( BinTree BT ); /* 先序遍历，由裁判实现，细节不表 */
void InorderTraversal( BinTree BT );  /* 中序遍历，由裁判实现，细节不表 */

BinTree Insert( BinTree BST, ElementType X );
BinTree Delete( BinTree BST, ElementType X );
Position Find( BinTree BST, ElementType X );
Position FindMin( BinTree BST );
Position FindMax( BinTree BST );

int main()
{
    BinTree BST, MinP, MaxP, Tmp;
    ElementType X;
    int N, i;

    BST = NULL;
    scanf("%d", &N);
    for ( i=0; i<N; i++ ) {
        scanf("%d", &X);
        BST = Insert(BST, X);
    }
    printf("Preorder:"); PreorderTraversal(BST); printf("\n");
    MinP = FindMin(BST);
    MaxP = FindMax(BST);
    scanf("%d", &N);
    for( i=0; i<N; i++ ) {
        scanf("%d", &X);
        Tmp = Find(BST, X);
        if (Tmp == NULL) printf("%d is not found\n", X);
        else {
            printf("%d is found\n", Tmp->Data);
            if (Tmp==MinP) printf("%d is the smallest key\n", Tmp->Data);
            if (Tmp==MaxP) printf("%d is the largest key\n", Tmp->Data);
        }
    }
    scanf("%d", &N);
    for( i=0; i<N; i++ ) {
        scanf("%d", &X);
        BST = Delete(BST, X);
    }
    printf("Inorder:"); InorderTraversal(BST); printf("\n");

    return 0;
}
BinTree Insert( BinTree BST, ElementType X )
{
	if(!BST)//为空时 
	{
		BinTree p=(BinTree)malloc(sizeof(BinTree));
		p->Data=X;
		p->Left=p->Right=NULL;
		BST=p;		
	}
	else if(X>BST->Data)
		BST->Right=Insert(BST->Right,X);
	else if(X<BST->Data)
		BST->Left=Insert(BST->Left,X);
	return BST;		
} 
Position FindMin( BinTree BST )
{
	if(BST)
	{
		if(BST->Left)
			return FindMin(BST->Left);
		else
			return BST;
	}
}
Position FindMax( BinTree BST )
{
    if(BST){
       if(BST->Right)return FindMax(BST->Right);
       else return BST;
    }
}
Position Find( BinTree BST, ElementType X )
{
    if(!BST)
		return NULL;
    if(BST->Data==X)
		return BST;
    else if(X<BST->Data)
		return Find(BST->Left,X);
    else if(X>BST->Data)
		return Find(BST->Right,X);
    return BST;
}
BinTree Delete( BinTree BST, ElementType X )
{//整个函数中没有改变BST的指向，全部为递归写法 
	if(!BST)//递归遍历下来为空，则表明未找到 
		printf("Not Found\n");
	else
	{
		if(X<BST->Data)
			BST->Left=Delete(BST->Left,X);
		else if(X>BST->Data)
			BST->Right=Delete(BST->Right,X);
		else if(X==BST->Data)
		{
			if(BST->Left&&BST->Right)
			{
				BinTree q=FindMin(BST->Right);
				BST->Data=q->Data;
				BST->Right=Delete(BST->Right,q->Data);
			}
			else
			{
				if(!BST->Left)//1为空 2.无子节点时通过此来返回空，做删除表示 
					BST=BST->Right;
				else if(!BST->Right)//为空 
					BST=BST->Left;
			}
		}
	}
	return BST;
}









 
