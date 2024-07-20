//https://www.acwing.com/problem/content/145/


#include<iostream>
using namespace std;
const int N=1e5+10;
const int M=3*N;
int str[M],son[N][2],idx;
void insert(int x)
{
    int p=0;
    for(int i=30;i>=0;i--){
        int u=x>>i&1;
        if(!son[p][u]) son[p][u]=idx++;
        p=son[p][u];
    }
}
int find(int x)
{
    int p=0,res=0;
    for(int i=30;i>=0;i--)
    {
        int u=x>>i&1;
        if(son[p][!u])
        {
            p=son[p][!u];
            res=res*2+1;//1是他们的异或值
        }else
        {
            p=son[p][u];
            res=res*2+0;
        }
    }
    return res;
}
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>str[i];
        insert(str[i]);
    }
    int res=0;
    for(int i=0;i<n;i++)
    {
        res=max(res,find(str[i]));
    }
    cout<<res<<endl;
    return 0;
}