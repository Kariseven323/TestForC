//https://www.acwing.com/problem/content/853/


#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
const int N=1e5+10;
int h[N],e[N],ne[N],idx,w[N];
int n,m;
int dist[N],st[N];
void init()
{
    memset(h,-1,sizeof h);
    idx=0;
}
void add(int a,int b,int c)
{
    e[idx]=b;
    w[idx]=c;
    ne[idx]=h[a];
    h[a]=idx;
    idx++;
}
int spfa()
{
    memset(dist,0x3f,sizeof dist);
    dist[1]=0;
    queue<int> q;
    q.push(1);
    st[1]=true;
    while(q.size())
    {
        int t=q.front();
        q.pop();
        st[t]=false;
        for(int i=h[t];i!=-1;i=ne[i])
        {
            int j=e[i];
            if(dist[j]>dist[t]+w[i])
            {
                dist[j]=dist[t]+w[i];
                if(!st[j])
                {
                    q.push(j);
                    st[j]=true;
                }
            }
        }
    }
    return dist[n]<0x3f3f3f3f/2;
}
int main()
{
    init();
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++)
    {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        add(a,b,c);
    }
    if(spfa()){
        cout<<dist[n]<<endl;
    }else{
        puts("impossible");
    }
    return 0;
}