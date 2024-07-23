//https://www.acwing.com/problem/content/855/


#include<iostream>
#include<cstring>
using namespace std;
const int N=510,M=1e4+10;
int n,m,k;
int dist[N],backup[N];
struct Edge
{
    int a,b,w;
}edges[M];
int bellman_ford()
{
    memset(dist,0x3f,sizeof dist);
    dist[1]=0;
    for(int i=0;i<k;i++)
    {
        memcpy(backup,dist,sizeof dist);
        for(int j=0;j<m;j++)
        {
            int a=edges[j].a,b=edges[j].b,w=edges[j].w;
            dist[b]=min(dist[b],backup[a]+w);
        }
    }
    if(dist[n]>0x3f3f3f3f/2) return -1;
    else return dist[n];
}
int main()
{
    scanf("%d%d%d",&n,&m,&k);
    for(int i=0;i<m;i++)
    {
        int a,b,w;
        scanf("%d%d%d",&a,&b,&w);
        edges[i]={a,b,w};
    }
    int t=bellman_ford();
    if(dist[n]<=0x3f3f3f3f/2)
    {
        printf("%d",t);
    }else{
        puts("impossible");
    }
    return 0;
}