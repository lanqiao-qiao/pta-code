List Insert( List L, ElementType X )
{
	List p=L,s,left;
	s=(List)malloc(sizeof(struct Node));
	if(p->Data>X)
	{
		s->Data=X;
		s->Next=p;
		L=s;
		return L;
	}
	else
	{
		while(p)
		{
			if(p->Data>X)
				break;
			left=p;
			p=p->Next;
		}
		s->Data=X;
		s->Next=left->Next;
		left->Next=s;
		//p=left;
		return L;
	}
} 
/*
List Insert( List L, ElementType X )
{
	List p=L,s,left=p;
	s=(List)malloc(sizeof(struct Node));
	while(p)
	{
		if(p->Data>X)
			break;
		left=p;
		p=p->Next;
	}
	s->Data=X;
	s->Next=left->Next;
	left->Next=s;
	//p=left;
	return L;
} 
*/
