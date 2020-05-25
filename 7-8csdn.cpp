#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<iostream>
using namespace std;
typedef struct BiTree
{
    char data[20];
    int lchild[20];
    int rchild[20];
}BiTree;
int Judge(BiTree T1, int pos1, BiTree T2, int pos2)
{
    int l1 =  T1.lchild[pos1];
    int r1 =  T1.rchild[pos1];
    int l2 =  T2.lchild[pos2];
    int r2 =  T2.rchild[pos2];
    if(T1.data[l1]==T2.data[l2]&&T1.data[r1]==T2.data[r2])
        return 1;
    if(T1.data[l1]==T2.data[r2]&&T1.data[r1]==T2.data[l2])
        return 1;
    return 0;
}
int BuildTree(BiTree &T)
{
    int N;
    scanf("%d", &N);
    for(int i=0; i<N; i++){
        getchar();//?scanf?????????,cin???
        char data, lchild, rchild;
        scanf("%c %c %c", &data, &lchild, &rchild);
        //cin>>data>>lchild>>rchild;
        T.data[i] = data;
        int l = lchild - '0';
        int r = rchild - '0';
        if(l < 0)
            l = 15;
        if(r < 0)
            r = 15;
        T.lchild[i] = l;
        T.rchild[i] = r;
    }
    T.data[15] = '1';
    return N;
}
int main()
{
    BiTree T1, T2;
    int N1 = BuildTree(T1);
    int N2 = BuildTree(T2);
    if(N1 != N2){//??????
        printf("No");
        return 0;
    }
    for(int i=0; i<N1; i++){
        int j;
        for(j=0; j<N2; j++){
            if(T1.data[i] == T2.data[j]){
               int is = Judge(T1, i, T2, j);
               if(!is){//???????????
                  printf("No");
                  return 0;
               }
               break;
            }
        }
        if(j == N2){//???
            printf("No");
            return 0;
        }
    }
    printf("Yes");
 
}
