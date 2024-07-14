//https://www.acwing.com/problem/content/799/


#include<iostream>
using namespace std;
const int N=1e5+10;
int b[N];
void insert(int l,int r,int c)
{
    b[l]+=c;
    b[r+1]-=c;
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        int c;
        scanf("%d",&c);
        insert(i,i,c);
    }
    while(m--)
    {
        int l,r,c;
        scanf("%d%d%d",&l,&r,&c);
        insert(l,r,c);
    }
    for(int i=1;i<=n;i++)
    {
        b[i]=b[i-1]+b[i];
        printf("%d ",b[i]);
    }
    return 0;
}