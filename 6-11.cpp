void InorderTraversal( BinTree BT )
{
	BinTree T=BT;
	Stack s;
	bool p;
	s=CreateStack();
	while(T||!IsEmpty(s))
	{
		while(T)
		{
			p=Push(s,T);
			T=T->Left;
		}
		T=Pop(s);
		printf(" %c",T->Data);
		T=T->Right;
	}
} 
void PreorderTraversal( BinTree BT )
{
	BinTree T=BT;
	Stack s;
	bool p;
	s=CreateStack();
	while(T||!IsEmpty(s))
	{
		while(T)
		{
			p=Push(s,T);
			printf(" %c",T->Data);
			T=T->Left;
		}
		T=Pop(s);
		T=T->Right;
	}
}
void PostorderTraversal( BinTree BT )
{
	BinTree T=BT;
	Stack s;
	bool p;
	s=CreateStack();
	while(T||!IsEmpty(s))
	{
		while(T)
		{
			p=Push(s,T);
			T->flag=0;
			T=T->Left;
		}
		T=Peek(s);
		if(T->flag==0)
		{
			T->flag=1;
			T=T->Right;
		}
		else
		{
			T=Pop(s);
			printf(" %c",T->Data);
			T=NULL;
		}
	}
}











