//https://www.acwing.com/problem/content/843/


#include<iostream>
using namespace std;
const int N=1e5+10;
char str[N];
const int P=13331;
unsigned long long h[N],p[N];
unsigned long long get(int l,int r)
{
    return h[r]-h[l-1]*p[r-l+1];
}
int main()
{
    p[0]=1;
    int n,m;
    scanf("%d%d",&n,&m);
    scanf("%s",str+1);//防止读取换行符
    for(int i=1;i<=n;i++)
    {
        p[i]=p[i-1]*P;
        h[i]=h[i-1]*P+str[i];
    }
    while(m--)
    {
        int l1,r1,l2,r2;
        scanf("%d%d%d%d",&l1,&r1,&l2,&r2);
        if(get(l1,r1)==get(l2,r2))
        {
            puts("Yes");
        }else{
            puts("No");
        }
    }
    return 0;
}