#include <iostream>
using namespace std;
struct node
{
	int p;
	int num;
};//这里用了一个结构体数组，p为0表示这个数不能是沙漏，1是沙漏。 
struct node a[1050];//num的值是这个沙漏最上边一行符号的个数，也是沙漏的行数 
void init()//用于结构体数组的初始化 
{
	int sum=0;//用来记录沙漏符号总数 
	int n;
	for(int i=0;i<1000;i++)//其实用不了这么多，所以下边用break终止 
	{//这里再算新加入的两行每行是几个符号 
		n=i*2+1;//用n表示，比如第三次增加的是5个符号 
		if(n==1)
			sum+=n;//第一个(一个符号的只有一个，特殊情况) 
		else
			sum+=2*n;//其他都是加两行 
		if(sum>1000)//总数超过1000停止循环，防止数组爆掉 
			break;
		a[sum].p=1;//标记这个数组 
		a[sum].num=n;//记录这个的行数 
		//cout<<sum<<endl;
	}
}
char str;//存储符号 
void print(int x)//打印沙漏的函数 
{
	int c=a[x].num;//获取行数 
	int c1=c;//表示当前打印符号数 
	int k=0;//表示当前打印空格数 
	for(int i=0;i<c/2+1;i++)//先打印上半部分，包括1个的 
	{
		for(int j=0;j<k;j++)
		{
			cout<<" ";
		}//先打印空格 
		for(int j=0;j<c1;j++)
		{
			cout<<str;
		}//打印符号 
		cout<<endl;
		k+=1;//每次空格多一个 
		c1-=2;//符号少两个 
	}
	c1=3;//重置，为打印下边的做准备 
	k=c/2-1;//含义同上 
	for(int i=0;i<c/2;i++)
	{
		for(int j=0;j<k;j++)
		{
			cout<<" ";
		}
		for(int j=0;j<c1;j++)
		{
			cout<<str;
		}
		cout<<endl;
		k-=1;
		c1+=2;//道理同上 
	}
}
int main()
{
	init();//调用 
	int n,j;
	cin>>n>>str;//输入 
	for(int i=n;i>=0;i--)
	{
		if(a[i].p==1)
		{
			j=i;
			break;	
		}
	}//获取最接近的沙漏数 
	print(j);
	cout<<n-j<<endl;//输出 
}
