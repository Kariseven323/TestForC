//https://www.acwing.com/problem/content/863/


#include<iostream>
#include<cstring>
using namespace std;
const int N=510;
const int M=1e5+10;
int h[N],e[M],ne[M],idx;
int n1,n2,m;
int match[N];
bool st[N];
void init()
{
    memset(h,-1,sizeof h);
    idx=0;
}
void add(int a,int b)
{
    e[idx]=b;
    ne[idx]=h[a];
    h[a]=idx;
    idx++;
}
bool dfs(int u)
{
    for(int i=h[u];i!=-1;i=ne[i])
    {
        int j=e[i];
        if(!st[j])
        {
            st[j]=true;
            if(!match[j]||dfs(match[j]))
            {
                match[j]=u;
                return true;
            }
        }
    }
    return false;
}
int main()
{
    init();
    cin>>n1>>n2>>m;
    while(m--)
    {
        int a,b;
        cin>>a>>b;
        add(a,b);
    }
    int res=0;
    for(int i=1;i<=n1;i++)
    {
        memset(st,0,sizeof st);
        if(dfs(i))
        {
            res++;
        }
    }
    cout<<res<<endl;
    return 0;
}