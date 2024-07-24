//https://www.acwing.com/problem/content/855/


#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
const int N=510,M=1e4+10;
int n,m,k;
int dist[N],backup[N];
struct Edge
{
    int v,w;
};
vector<Edge> e[N];
bool bellman_ford() {
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    for (int i = 1; i <= k; i++) {
        memcpy(backup, dist, sizeof dist);
        for (int u = 1; u <= n; u++) {
            if (backup[u] > 0x3f3f3f3f / 2) continue;
            for (auto ed : e[u]) {
                int v = ed.v, w = ed.w;
                if (dist[v] > backup[u] + w) {
                    dist[v] = backup[u] + w;
                }
            }
        }
    }
    return dist[n]<0x3f3f3f3f/2;
}
int main()
{
    scanf("%d%d%d",&n,&m,&k);
    for(int i=0;i<m;i++)
    {
        int a,b,w;
        scanf("%d%d%d",&a,&b,&w);
        e[a].push_back({b,w});
    }
    if(bellman_ford())
    {
        printf("%d",dist[n]);
    }else{
        puts("impossible");
    }
    return 0;
}