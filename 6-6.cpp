List Merge( List l1, List l2 )
{
	List head,L1,L2;
	L1=l1;
	L2=l2;
	List L;
	head=(List)malloc(sizeof(struct Node));
	L=head;
	L1=L1->Next;
	L2=L2->Next;
	while(L1&&L2)
	{
		if(L1->Data<=L2->Data)
		{
			L->Next=L1;
			L=L1;
			L1=L1->Next;
		}
		else
		{
			L->Next=L2;
			L=L2;
			L2=L2->Next;
		}
	}
	if(L1)
	{
		L->Next=L1;
		L1->Next=NULL;
	}
	else
	{
		L->Next=L2;
		L2->Next=NULL;
	}
	return head;
}
