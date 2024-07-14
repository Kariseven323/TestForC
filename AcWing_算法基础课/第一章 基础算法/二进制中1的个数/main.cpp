//https://www.acwing.com/problem/content/803/


#include<iostream>
using namespace std;
const int N=1e5+10;
int a[N];
int lowbit(int x)
{
    return x&-x;
}
int main()
{
    int n;
    cin>>n;
    while(n--)
    {
        int x;
        cin>>x;
        int sum=0;
        while(x){
            if(lowbit(x)){
                sum++;
            }
            x=x- lowbit(x);
        }
        cout<<sum<<" ";
    }
    return 0;
}