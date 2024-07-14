//https://www.acwing.com/problem/content/797/


#include<iostream>
using namespace std;
const int N=1e5+10;
int a[N],s[N];
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        s[i]=s[i-1]+a[i];
    }
    while(m--)
    {
        int l,r;
        cin>>l>>r;
        printf("%d\n",s[r]-s[l]+a[l]);
    }
    return 0;
}