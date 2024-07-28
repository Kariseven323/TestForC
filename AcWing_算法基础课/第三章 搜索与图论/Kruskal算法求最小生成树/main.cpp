//https://www.acwing.com/problem/content/861/


#include<iostream>
#include<cstring>
#include<vector>
#include <algorithm>
using namespace std;
int n,m;
const int N=1e5+10;
const int M=2e5+10;
int p[N];
struct edge
{
    int a,b,w;
    bool operator < (const edge &W)
    {
        return w<W.w;
    }
}edges[M];
int find(int x)
{
    if(p[x]!=x) p[x]=find(p[x]);
    return p[x];
}
int kruskal()
{
    int res=0,cnt=0;
    sort(edges,edges+m);
    for(int i=1;i<=n;i++)
    {
        p[i]=i;
    }
    for(int i=0;i<m;i++)
    {
        int a=edges[i].a,b=edges[i].b,w=edges[i].w;
        a=find(a),b=find(b);
        if(a!=b)
        {
            p[a]=b;
            res+=w;
            cnt++;
        }
    }
    if(cnt<n-1) return 0x3f3f3f3f;
    return res;
}
int main()
{
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        cin>>edges[i].a>>edges[i].b>>edges[i].w;
    }
    int result=kruskal();
    if(result==0x3f3f3f3f) puts("impossible");
    else cout<<result<<endl;
    return 0;
}