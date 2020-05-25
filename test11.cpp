

 #include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct PolyNode* Polynomial;
struct PolyNode {
	int coef;
	int expon;
	Polynomial link;
};
void menu()
{

	printf("欢迎使用此多项式计算器\n");
	printf("1.加法\n2.减法\n3.乘法\n");
	printf("请输入你的选择:");

}
void attach(int c, int e, Polynomial* prear)
{
	Polynomial P;
	P = (Polynomial)malloc(sizeof(struct PolyNode));
	P->coef = c;
	P->expon = e;
	P->link = NULL;
	(*prear)->link = P;
	*prear = P;
}
Polynomial readpoly(int *m)
{
	
	Polynomial P, rear, t;
	int c, e, N;
	printf("请输入第%d个多项式的项数:",*m);
	scanf("%d", &N);
	P = (Polynomial)malloc(sizeof(struct PolyNode));
	P->link = NULL;
	rear = P;
	  printf("请输入第%d个多项式:",*m);
	while (N--) {
		scanf("%d%d", &c, &e);
		attach(c, e, &rear);
	}
	t = P; P = P->link; free(t);*m+=1;
	//printf("#\n");
	return P;
}
Polynomial mult(Polynomial p1, Polynomial p2)//乘法
{
	Polynomial p, rear, t1, t2, t;
	int c, e;
	if (!p1 || !p2)return NULL;
	t1 = p1; t2 = p2;
	p = (Polynomial)malloc(sizeof(struct PolyNode)); p->link = NULL;
	rear = p;
	while (t2)
	{
		attach(t1->coef * t2->coef, t1->expon + t2->expon, &rear);
		t2 = t2->link;
	}
	t1 = t1->link;
	while (t1)
	{
		t2 = p2; rear = p;
		while (t2)
		{
			e = t1->expon + t2->expon;
			c = t1->coef * t2->coef;
			while (rear->link && rear->link->expon > e)
				rear = rear->link;
			if (rear->link && rear->link->expon == e) {
				if (rear->link->coef + c)
					rear->link->coef += c;
				else {
					t = rear->link;
					rear->link = t->link;
					free(t);
				}
			}
			else {
				t = (Polynomial)malloc(sizeof(struct PolyNode));
				t->coef = c; t->expon = e;
				t->link = rear->link;
				rear->link = t; rear = rear->link;
			}
			t2 = t2->link;
		}
		t1 = t1->link;
	}
	t2 = p; p = p->link; free(t2);
	return p;
}
Polynomial add(Polynomial p1, Polynomial p2)//加法
{
	Polynomial front, rear, temp;
	int sum;
	rear = (Polynomial)malloc(sizeof(struct PolyNode));
	front = rear;
	while (p1 && p2)
	{
		if (p1->expon > p2->expon)
		{
			attach(p1->coef, p1->expon, &rear);
			p1 = p1->link;
			if (p1 == NULL)break;
		}
		if (p1->expon < p2->expon)
		{
			attach(p2->coef, p2->expon, &rear);
			p2 = p2->link;
			if (p2 == NULL)break;
		}
		if (p1->expon == p2->expon)
		{
			sum = p1->coef + p2->coef;
			if (sum)attach(sum, p1->expon, &rear);
			p1 = p1->link;
			p2 = p2->link;
		}
	}//比较部分中，遇到了问题，请教了席晨晨同学


	for (; p1; p1 = p1->link)attach(p1->coef, p1->expon, &rear);
	for (; p2; p2 = p2->link)attach(p2->coef, p2->expon, &rear);
	rear->link = NULL;
	temp = front;
	front = front->link;
	free(temp);
	return front;
}
void PrintPoly(Polynomial P)//输出
{ /* 输出多项式 */
	int flag = 0; /* 辅助调整输出格式用 */
	if (!P) { printf("0 0\n"); return; }
	while (P) {
		if (!flag)
			flag = 1;
		else
			printf(" ");
		printf("%d %d", P->coef, P->expon);
		P = P->link;
	}
	printf("\n");
}
Polynomial suv(Polynomial p1, Polynomial p2)
{
	Polynomial front, rear, temp;
	int sum;
	rear = (Polynomial)malloc(sizeof(struct PolyNode));
	front = rear;
	while (p1 && p2)
	{
		if (p1->expon > p2->expon)
		{
			attach(p1->coef, p1->expon, &rear);
			p1 = p1->link;
			if (p1 == NULL)break;
		}
		if (p1->expon < p2->expon)
		{
			attach(p2->coef, p2->expon, &rear);
			p2 = p2->link;
			if (p2 == NULL)break;
		}
		if (p1->expon == p2->expon)
		{
			sum = p1->coef - p2->coef;
			if (sum)attach(sum, p1->expon, &rear);
			p1 = p1->link;
			p2 = p2->link;
		}
	}//比较部分中，遇到了问题，请教了席晨晨同学


	for (; p1; p1 = p1->link)attach(p1->coef, p1->expon, &rear);
	for (; p2; p2 = p2->link)attach(p2->coef, p2->expon, &rear);
	rear->link = NULL;
	temp = front;
	front = front->link;
	free(temp);
	return front;
}
int main()
{
	Polynomial p1, p2, pp1, pp2, ps;
	//printf("请输入两个多项式：");
	int m=1;
	p1 = readpoly(&m);
	p2 = readpoly(&m);
	menu();
	int a;
	scanf ("%d",&a);
	if(a==1)
	{pp1 = mult(p1, p2);
	PrintPoly(pp1);
	}
	if(a==2)
	{pp2 = suv(p1, p2);
	PrintPoly(pp2);
	}
	if (a==3)
	{ps = add(p1, p2);
	PrintPoly(ps);
	}
	return 0;

}

