
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




