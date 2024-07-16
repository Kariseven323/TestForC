//https://www.acwing.com/problem/content/837/


#include<iostream>
#include <cstring>
using namespace std;
const int N=2e5+10;
int cnt[N],son[N][26],idx;
char str[N];
void insert()
{
    int p=0;
    for(int i=0;str[i];i++)
    {
        int u=str[i]-'0';
        if(!son[p][u]) son[p][u]=++idx;
        p=son[p][u];
    }
    cnt[p]++;
}
int query()
{
    int p=0;
    for(int i=0;str[i];i++)
    {
        int u=str[i]-'0';
        if(!son[p][u]) return 0;
        p=son[p][u];
    }
    return cnt[p];
}
int main()
{
    cin.tie(0);
    int n;
    cin>>n;
    while(n--)
    {
        char op[2];
        cin>>op>>str;
        if(!strcmp(op,"I"))
        {
            insert();
        }else{
            cout<<query()<<endl;
        }
    }
    return 0;
}