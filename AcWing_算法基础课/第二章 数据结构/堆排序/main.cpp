//https://www.acwing.com/problem/content/840/


#include<iostream>
using namespace std;
const int N=1e6+10;
int a[N],cnt;
void up(int u){
    if(u/2&&a[u/2]>a[u]) swap(a[u],a[u/2]),up(u/2);
}
void push(int x){
    a[++cnt]=x;
    up(cnt);
}
void down(int u)
{
    int v=u;
    if(u*2<=cnt&&a[u*2]<a[v]) v=u*2;
    if(u*2+1<=cnt&&a[u*2+1]<a[v]) v=u*2+1;
    if(u!=v) swap(a[u],a[v]),down(v);
}
void pop()
{
    a[1]=a[cnt--];
    down(1);
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        int x;
        scanf("%d",&x);
        push(x);
    }
    for(int i=1;i<=m;i++)
    {
        printf("%d ",a[1]);
        pop();
    }
    return 0;
}