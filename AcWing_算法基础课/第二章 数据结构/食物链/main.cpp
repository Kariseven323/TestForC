//https://www.acwing.com/problem/content/242/


#include<iostream>
using namespace std;
const int N=5e4+10;
int p[N],siz[N];
int find(int x)//路径压缩+边权转移 ps：可以画图理解
{
    if(p[x]==x) return p[x];
    int t=find(p[x]);
    siz[x]=siz[x]+siz[p[x]];
    p[x]=t;
    return p[x];
}
int main()
{
    int n,m;
    int res=0;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        p[i]=i;
    }
    while(m--)
    {
        int d,x,y;
        scanf("%d%d%d",&d,&x,&y);
        if((x>n||y>n)||(d==2&&(x==y)))
        {
            res++;
        }else{
            int a=find(x),b=find(y);
            if(a==b)
            {
                if(d==1)
                {
                    if((siz[x]-siz[y]+3)%3!=0) res++;//同类路径之差对3取模一定为0
                }else
                {
                    if((siz[x]-siz[y]-1)%3!=0) res++;//x吃y，那么路径之差对3取模一定为1
                }
            }else
            {
                p[a]=b;//a集合合并至b集合
                if(d==2)
                    siz[a]=siz[y]-siz[x]+1;//合并并查集时因为两个集合不在同一层面，所以需要加一
                else
                    siz[a]=siz[y]-siz[x];
            }
        }
    }
    cout<<res<<endl;
    return 0;
}