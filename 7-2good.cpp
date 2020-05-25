#include <iostream>
#include <cstdio>
using namespace std;
int s1[100050],l[100050],r[100050],l2[100050];
int main()
{
	int first,num,c,q;
	cin>>first>>num>>c;
	for(int i=0;i<num;i++)
	{
		int x,y,z;
		cin>>x>>y>>z;
		s1[x]=y;
		r[x]=z;
	}
	//cout<<s[q].n<<endl;
	int sum=0;
	while(first!=-1)
	{
		l[sum++]=first;
		first=r[first];
		//cout<<first<<endl;
	}
	//for(int i=0;i<num;i++)
	//	cout<<l[i]<<endl;
	if(c==0)
	{
		for(int i=0;i<sum;i++)
			l2[i]=l[i];
	}
	else
	{
		int ci=sum/c;
		for(int i=0;i<ci;i++)
		{
			int pr=(i+1)*c-1;
			int pl=i*c;
			int cc=c;
			while(cc--)
			{
				//cout<<pl<<' '<<pr<<endl;
				l2[pl]=l[pr];
				pl++;
				pr--;
			}
		}
		int summ=sum-1;
		int nn=sum%c;
		//cout<<nn<<"&"<<endl;
		while(nn--)
		{
			l2[summ]=l[summ];
			//cout<<s2[numm].n<<"@"<<endl;
			summ--;
		}	
	}
	for(int i=0;i<sum-1;i++)
	{
		printf("%05d %d %05d\n",l2[i],s1[l2[i]],l2[i+1]);
	}
	printf("%05d %d -1\n",l2[sum-1],s1[l2[sum-1]]);
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

10 11 1
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
99 999 9999
*/

