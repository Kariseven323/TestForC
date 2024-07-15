//https://www.acwing.com/problem/content/828/


#include<iostream>
using namespace std;
const int N=1e5+10;
//head表示头结点下标
//e[i]表示节点i的值
//ne[i]表示节点i的next指针是多少
//idx存储当前已经用到了哪个节点
int head,e[N],ne[N],idx;
void init()
{
    head=-1;
    idx=0;
}

void add_to_head(int x)
{
    e[idx]=x;
    ne[idx]=head;
    head=idx;
    idx++;
}

void delete_to_k(int k)
{
    ne[k]=ne[ne[k]];
}

void add_to_k(int k,int x)
{

}

int main()
{
    int m;
    cin>>m;
    init();
    while(m--)
    {
        char op;
        cin>>op;
        if(op=='H'){
            int x;
            cin>>x;
            add_to_head(x);
        }else if(op=='D'){
            int k;
            cin>>k;
            if(k==0) head=ne[head];
            else delete_to_k(k-1);
        }else{
            int k,x;
            cin>>k>>x;
            add_to_k(k-1,x);
        }
    }
    for(int i=head;i!=-1;i=ne[i]) cout<<e[i]<<" ";
    return 0;
}