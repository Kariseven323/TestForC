//https://www.acwing.com/problem/content/839/


#include<iostream>
using namespace std;
const int N=1e5+10;
int p[N],siz[N];
int find(int x)
{
    if(p[x]!=x) p[x]=find(p[x]);
    return p[x];
}
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        p[i]=i;
        siz[i]=1;
    }
    while(m--)
    {
        string op;
        cin>>op;
        if(op=="Q1")
        {
            int a,b;
            scanf("%d%d",&a,&b);
            if(find(a)==find(b))
                puts("Yes");
            else{
                puts("No");
            }
        }else if(op=="Q2")
        {
            int a;
            scanf("%d",&a);
            cout<<siz[find(a)]<<endl;
        }else{
            int a,b;
            scanf("%d%d",&a,&b);
            a=find(a),b=find(b);//先找父节点，防止出现结点重叠的情况，即孙子变爷爷
            if(a!=b) {
                p[b]=a;
                siz[a] += siz[b];
            }
        }
    }
    return 0;
}