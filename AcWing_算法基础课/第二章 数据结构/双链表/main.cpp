#include<iostream>

using namespace std;

const int N = 100010;

int m;
int e[N],l[N],r[N],idx;

void init()
{
    r[0] = 1,l[1] = 0;
    idx=2;
}

void add_to_right(int k,int x)
{
    e[idx] = x;
    r[idx] = r[k];
    l[idx] = k;
    l[r[k]] = idx;
    r[k] = idx ++ ;
}

void add_to_left(int k,int x)
{
    add_to_right(l[k],x);
}

void remove(int k)
{
    r[l[k]] = r[k];
    l[r[k]] =l[k];
}

void add_to_head(int x)
{
    add_to_right(0,x);
}

void add_to_tail(int x)
{
    add_to_right(l[1],x);
}

int main()
{
    int m;

    init();

    scanf("%d",&m);
    while (m -- )
    {
        string c;
        cin >> c;

        if(c == "L")
        {
            int x;
            scanf("%d", &x);
            add_to_head(x);
        }
        else if(c == "R")
        {
            int x;
            scanf("%d", &x);
            add_to_tail(x);
        }
        else if(c == "D")
        {
            int k;
            scanf("%d", &k);
            remove(k + 1);
        }
        else if(c == "IL")
        {
            int k,x;
            scanf("%d%d", &k, &x);

            add_to_left(k + 1,x);
        }
        else
        {
            int k,x;
            scanf("%d%d", &k, &x);

            add_to_right(k + 1,x);
        }

    }

    for (int i = r[0]; i != 1; i = r[i])
    {
        printf("%d ",e[i]);
    }
    printf("\n");
    return 0;
}
