//https://www.acwing.com/problem/content/842/


#include<iostream>
#include<algorithm>
using namespace std;
const int N=1e5+10;
int h[N],e[N],ne[N],idx;
void init()
{
    fill(h,h+N,-1);
}
void insert(int x)
{
    int k=(x%N+N)%N;
    e[idx]=x;
    ne[idx]=h[k];
    h[k]=idx;
    idx++;
}
bool query(int x)
{
    int k=(x%N+N)%N;
    for(int i=h[k];i!=-1;i=ne[i])
    {
        if(e[i]==x) return true;
    }
    return false;
}
int main()
{
    init();
    int n;
    scanf("%d",&n);
    while(n--)
    {
        char op[2];
        int x;
        scanf("%s%d",op,&x);
        if(*op=='I')
        {
            insert(x);
        }else{
            if(query(x))
            {
                puts("Yes");
            }else{
                puts("No");
            }
        }
    }
}