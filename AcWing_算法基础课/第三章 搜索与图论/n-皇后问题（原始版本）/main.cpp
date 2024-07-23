//https://www.acwing.com/problem/content/845/


#include<iostream>
using namespace std;
const int N=10;
char g[N][N];
int n;
bool col[2*N],row[2*N],dg[2*N],udg[2*N];
void dfs(int x,int y,int s)
{
    if(y==n) y=0,x++;
    if(x==n){
        if(s==n)
        {
            for(int i=0;i<n;i++) puts(g[i]);
            puts("");
        }
        return ;
    }
    dfs(x,y+1,s);
    if(!row[x]&&!col[y]&&!dg[x+y]&&!udg[x-y+n])
    {
        g[x][y]='Q';
        row[x]=col[y]=dg[x+y]=udg[x-y+n]=true;
        dfs(x,y+1,s+1);
        row[x]=col[y]=dg[x+y]=udg[x-y+n]=false;
        g[x][y]='.';
    }
}
int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            g[i][j]='.';
    dfs(0,0,0);
    return 0;
}