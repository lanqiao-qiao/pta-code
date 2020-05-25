
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std ;
char s[1100005] , p[1100005] ;
const int MAX = 1005 ;
typedef long long LL ;
int nxt[MAX] ; // next数组
void getNext(char *p){
	int plen = strlen(p) ;
	nxt[0] = -1 ;
	int k = -1 ;
	int j = 0 ;
	while(j<plen -1 ){
		if(k == -1 || p[j]==p[k]){
			k++ ;
			j++ ;
			nxt[j] = k ;
		}
		else{
			k = nxt[k] ;
		}
	}
}
void getNextVal(char *p){
	int plen = strlen(p) ;
	nxt[0] = -1 ;
	int k = -1 ;
	int j = 0 ;
	while(j<plen){
		if(k == -1 || p[j]==p[k]){
			j++ ;
			k++ ;
			if(p[j]!=p[k]){
				nxt[j] = k ;
			}
			else{
				nxt[j] = nxt[k] ;
			}
		}
		else{
			k = nxt[k] ;
		}
	}
}
int kmp(char *s , char *p) {
	// s 是模式串, p 是匹配串
    int i = 0 , j = 0 ;
    //getNext(p) ; // 得到匹配串的next数组
    getNextVal(p) ;
    int slen = strlen(s) ;
    int plen = strlen(p) ;
    while(i<slen && j <plen ){
    	if(j == -1 || s[i]==p[j]){
    		i++ ;
    		j++ ;
		}
		else{
			j = nxt[j] ;
		}
	}
	if(j == plen ){
		return i-j ;
	}
	else{
		return -1 ;
	}
	
}
int main(){
	cin >>s ;
	int n;
	cin>>n;
	while(n--)
	{
		cin>>p;
		int pos = kmp(s,p) ;
		if(pos==-1)
			cout<<"Not Found"<<endl;
		else
		{
			for(int i=pos;i<strlen(s);i++)
				cout<<s[i];	
			cout<<endl;
		}
				
		//cout<<pos <<endl ;
	}
	return 0 ;
}
