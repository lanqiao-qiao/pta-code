#include <stdio.h>
#include <stdlib.h>

typedef char ElementType;
typedef struct TNode *Position;
typedef Position BinTree;
struct TNode{
    ElementType Data;//char Data
    BinTree Left;//*TNode
    BinTree Right;
};

BinTree CreatBinTree(); /* ÊµÏÖÏ¸½ÚºöÂÔ */
int GetHeight( BinTree BT );

int main()
{
    BinTree BT = CreatBinTree();
    printf("%d\n", GetHeight(BT));
    return 0;
}
int GetHeight( BinTree BT )
{
	int l,r;
	if(BT==NULL)
		return 0;
	else
	{
		l=GetHeight(BT->Left);
		r=GetHeight(BT->Right);
		return (l>r?l:r)+1;	
	} 
}
