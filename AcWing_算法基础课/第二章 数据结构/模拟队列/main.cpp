//https://www.acwing.com/problem/content/831/


#include<iostream>

using namespace std;

const int N = 100010;
int q[N],hh,tt=-1;

int main()
{
    int m;
    cin >> m;
    while(m--)
    {
        string op;
        cin >> op;
        if(op=="push")
        {
            int x;
            cin >> x;
            q[++tt] = x;
        }
        if(op=="pop")
        {
            hh++;
        }
        if(op=="empty")
        {
            if(hh<=tt)
            {
                puts("NO");
            }else{
                puts("YES");
            }
        }
        if(op=="query")
        {
            cout << q[hh] << endl;
        }
    }
    return 0;
}