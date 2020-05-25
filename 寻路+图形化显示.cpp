#include <iostream>
#include <windows.h>
#include <shellapi.h> 
#include <fstream>
#include <stack>
using namespace std;
int num_city;//城市总数
int dis[25][25];//距离 
int spe[25][25];//速度 
double Time[25][25];//时间 
int f1[25][25];
int f2[25][25];

void init_map()
{
	for(int i=1;i<=num_city;i++)
	{
		for(int j=1;j<=num_city;j++)
		{
			if(i==j)
			{
				dis[i][j]=spe[i][j]=Time[i][j]=0;
			}
			else
				dis[i][j]=spe[i][j]=Time[i][j]=9999;
		}
	}
}
void getdata()
{
	ifstream in("D:\\map.txt",ios::in);
	if(!in)
	{
		cout<<"获取默认数据失败"<<endl;
		exit(1);
	}
	in>>num_city;
	init_map();
	int a,b,c,d;
	while(in)
	{
		in>>a>>b>>c>>d;
		dis[a][b]=dis[b][a]=c;
		spe[a][b]=spe[b][a]=d;
		Time[a][b]=Time[b][a]=double(c)/double(d);
		//cout<<a<<' '<<b<<' '<<c<<' '<<d<<endl;
	}
}

void out_data()
{
	cout<<endl;
	for(int i=1;i<=num_city;i++)
	{
		for(int j=1;j<=num_city;j++)
		{
			cout<<i<<' '<<j<<' '<<dis[i][j]<<' '<<spe[i][j]<<' '<<Time[i][j]<<endl;
		}
	}
}
void open_exe()
{
	cout<<"解析中......"<<endl;
	Sleep(2000);
	ShellExecute(NULL, "open", "C:\\Users\\89469\\source\\repos\\数据结构窗体\\数据结构窗体\\bin\\Debug\\数据结构窗体.exe",NULL, NULL,SW_SHOW );
}
void init()
{
	cout<<"选择数据获取方式："<<endl;
	cout<<"1.从文本读入默认信息"<<endl;
	cout<<"2.自己输入数据"<<endl;
	cout<<"3.测试生成地图"<<endl;
	int i;
	cin>>i;
	if(i==1)
	{
		getdata();
		//out_data();
	}
	if(i==3)
	{
		open_exe();
	}
}

void floyd1()
{
	for(int k=1;k<=num_city;k++)
	{
		for(int i=1;i<=num_city;i++)
		{
			for(int j=1;j<=num_city;j++)
			{
				if(dis[i][j]>dis[i][k]+dis[k][j])
				{
					dis[i][j]=dis[i][k]+dis[k][j];
					f1[i][j]=k;
				}
				
			}
		}
	}
}

void floyd2()
{
	for(int k=1;k<=num_city;k++)
	{
		for(int i=1;i<=num_city;i++)
		{
			for(int j=1;j<=num_city;j++)
			{
				if(Time[i][j]>Time[i][k]+Time[k][j])
				{
					Time[i][j]=Time[i][k]+Time[k][j];
					f2[i][j]=k;
				}
			}
		}
	}
}

void out_f1()
{
	for(int i=1;i<=num_city;i++)
	{
		for(int j=1;j<=num_city;j++)
		{
			cout<<i<<' '<<j<<' '<<f1[i][j]<<endl;
		}
	}
}

void out_f2()
{
	for(int i=1;i<=num_city;i++)
	{
		for(int j=1;j<=num_city;j++)
		{
			cout<<i<<' '<<j<<' '<<f2[i][j]<<endl;
		}
	}
}

void select1()
{
	cout<<"输入你的出发地和目的地"<<endl;
	int a,b,bb;
	cin>>a>>b;
	bb=b;
	cout<<"选择时间优先(1)还是路程优先(2)"<<endl;
	int p;
	cin>>p;
	stack<int> s;
	double pri;
	int num=1;
	if(p==1)
	{
		pri=Time[a][b];
		while(f2[a][b])
		{
			s.push(f2[a][b]);
			b=f2[a][b];
			num++;
		}
		
	}
	else if(p==2)
	{
		pri=dis[a][b];
		while(f1[a][b])
		{
			//cout<<f1[a][b]<<endl;
			s.push(f1[a][b]);
			b=f1[a][b];
			num++;
		}
	}
	else
	{
		cout<<"这都能输错？？"<<endl; 
	}
	ofstream out("D:/map_data.txt", ios::out);
	if (!out)
	{
		cout << "数据转换出现错误" << endl;
		exit(1);
	}
	num++; 
	out<<num<<endl;
	out<<pri<<endl;
	//cout<<a<<' ';
	out<<a<<endl;
	while(s.size())
	{
		int q=s.top();
		//cout<<q<<' ';
		out<<q<<endl;
		s.pop();
	}
	out<<bb<<endl;
}


int main()
{
	init();
	floyd1(); 
	floyd2();
	out_data();
	out_f1();
	out_f2();
	select1();
	open_exe();
	
}
