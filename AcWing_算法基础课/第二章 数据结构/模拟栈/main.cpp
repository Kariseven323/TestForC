//https://www.acwing.com/problem/content/830/


#include<iostream>
using namespace std;
const int N=1e5+10;
int skt[N],tt;
void add(int x)
{
    tt++;
    skt[tt]=x;
}
void remove()
{
    tt--;
}
bool IsEmpty()
{
    if(tt>0) puts("NO");
    else return puts("YES");
}
int pop()
{
    return skt[tt];
}
int main()
{
    int m;
    cin>>m;
    while(m--)
    {
        string op;
        cin>>op;
        if(op=="push"){
            int x;
            cin>>x;
            add(x);
        }
        if(op=="query"){
            cout<<pop()<<endl;
        }
        if(op=="pop"){
            tt--;
        }
        if(op=="empty"){
            IsEmpty();
        }
    }
    return 0;
}