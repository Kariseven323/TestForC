//https://www.acwing.com/problem/content/862/


#include<iostream>
#include<cstring>
using namespace std;
int n,m;
const int N=1e6+10;
int h[N],e[N],ne[N],idx;
int color[N];
void init()
{
    memset(h,-1,sizeof h);
}
void add(int a,int b)
{
    e[idx]=b;
    ne[idx]=h[a];
    h[a]=idx;
    idx++;
}
bool dfs(int x,int c)
{
    color[x]=c;
    for(int i=h[x];i!=-1;i=ne[i])
    {
        int j=e[i];
        if(!color[j])
        {
            if(!dfs(j,3-c))
            {
                return false;
            }
        }else if(color[j]&&color[j]!=3-c)
        {
            return false;
        }
    }
    return true;
}
int main()
{
    init();
    cin>>n>>m;
    while(m--)
    {
        int a,b;
        cin>>a>>b;
        add(a,b),add(b,a);
    }
    for(int i=1;i<=n;i++)
    {
        if(!color[i])
        {
            if(!dfs(i,1))
            {
                cout<<"No"<<endl;
                return 0;
            }
        }
    }
    cout<<"Yes"<<endl;
    return 0;
}