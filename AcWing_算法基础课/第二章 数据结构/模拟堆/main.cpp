//https://www.acwing.com/problem/content/841/


#include<iostream>
using namespace std;
const int N=1e6+10;
int ph[N],hp[N],h[N],idx,len;
void heap_swap(int a,int b)
{
    swap(ph[hp[a]],ph[hp[b]]);
    swap(hp[a],hp[b]);
    swap(h[a],h[b]);
}
void up(int u)
{
    if(u/2&&h[u/2]>h[u])
    {
        heap_swap(u,u/2);
        up(u/2);
    }
}
void push(int x)
{
    h[++idx]=x;
    ph[idx]=++len;
    hp[len]=idx;
    up(idx);
}
void down(int u)
{
    int v=u;
    if(u*2<=idx&&h[u*2]<h[v]) v=u*2;
    if(u*2+1<=idx&&h[u*2+1]<h[v]) v=u*2+1;
    if(u!=v) heap_swap(u,v),down(v);
}
int main()
{
    int n;
    scanf("%d",&n);
    while(n--)
    {
        string op;
        cin>>op;
        if(op=="I")
        {
            int x;
            scanf("%d",&x);
            push(x);
        }
        if(op=="PM")
        {
            printf("%d\n",h[1]);
        }
        if(op=="DM")
        {
            heap_swap(1,idx--);
            down(1);
        }
        if(op=="D")
        {
            int k;
            scanf("%d",&k);
            k=ph[k];
            heap_swap(k,idx--);
            up(k);
            down(k);
        }
        if(op=="C")
        {
            int k,x;
            scanf("%d%d",&k,&x);
            k=ph[k];
            h[k]=x;
            up(k);
            down(k);
        }
    }
    return 0;
}