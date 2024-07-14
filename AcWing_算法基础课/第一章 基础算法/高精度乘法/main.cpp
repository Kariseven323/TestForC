//https://www.acwing.com/problem/content/795/


#include<iostream>
#include<vector>
using namespace std;
vector<int> mul(vector<int> &A,int b)
{
    vector<int> C;
    int t=0;
    for(int i=0;i<A.size();i++){
        t+=A[i]*b;
        C.push_back(t%10);
        t/=10;
    }
    if(t) C.push_back(t);
    while(C.back()==0&&C.size()>1) C.pop_back();
    return C;
}
int main()
{
    string a;
    int b;
    cin>>a>>b;
    vector<int> A;
    for(int i=a.size()-1;i>=0;i--) A.push_back(a[i]-'0');
    vector<int> C=mul(A,b);
    for(int i=C.size()-1;i>=0;i--) printf("%d",C[i]);
    return 0;
}