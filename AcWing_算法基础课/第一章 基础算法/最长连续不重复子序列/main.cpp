//https://www.acwing.com/problem/content/801/


#include<iostream>
using namespace std;
const int N=1e5+10;
int a[N],s[N];
int main()
{
    int n;
    cin>>n;
    int res=0;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1,j=1;i<=n;i++)
    {
        s[a[i]]++;
        while(j<=i&&s[a[i]]>1){
            s[a[j]]--;
            j++;
        }
        res=max(res,i-j+1);
    }
    cout<<res<<endl;
    return 0;
}