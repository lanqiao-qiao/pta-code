#include <iostream>
#include <cstdio>
using namespace std;
struct listt
{
	int l;
	int n;
	int r;
};
struct listt s[100050],s1[100050],s2[100050];
int main()
{
	int first,num,c,q;
	cin>>first>>num>>c;
	for(int i=0;i<num;i++)
	{
		cin>>s[i].l>>s[i].n>>s[i].r;
		if(s[i].l==first)
			q=i;
	}
	//cout<<s[q].n<<endl;
	s1[0]=s[q];
	int find=s1[0].r;
	for(int i=1;i<num;i++)
	{
		int p;
		for(int j=0;j<num;j++)
		{
			if(s[j].l==find)
			{
				//cout<<s[j].n<<endl;
				p=j;
				find=s[j].r;
				//cout<<"@"<<find<<endl;
				break;
			}
		}
		s1[i]=s[p];
		//cout<<p<<endl;
	}
	//for(int i=0;i<num;i++)
	//{
	//	cout<<s1[i].n<<endl;
	//}
	int ci=num/c;
	for(int i=0;i<ci;i++)
	{
		int pr=(i+1)*c-1;
		int pl=i*c;
		int cc=c;
		while(cc--)
		{
			//cout<<pl<<' '<<pr<<endl;
			s2[pl]=s1[pr];
			pl++;
			pr--;
		}
	}
	int numm=num-1;
	int nn=num%c;
	//cout<<nn<<"&"<<endl;
	while(nn--)
	{
		s2[numm]=s1[numm];
		//cout<<s2[numm].n<<"@"<<endl;
		numm--;
	}
	for(int i=0;i<num-1;i++)
	{
		printf("%05d %d %05d\n",s2[i].l,s2[i].n,s2[i+1].l);
	}
	printf("%05d %d -1\n",s2[num-1].l,s2[num-1].n);
}
/*
00100 6 6
00000 4 99999
00100 1 12309
68237 6 -1
33218 3 00000
99999 5 68237
12309 2 33218

00100 6 2
00000 4 99999
00100 1 12309
68237 6 -1
33218 3 00000
99999 5 68237
12309 2 33218

10 10 7
10 0 11
11 1 12
12 2 13
14 4 15
16 6 17
15 5 16
13 3 14
19 9 -1
17 7 18
18 8 19
*/

