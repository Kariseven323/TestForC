//https://www.acwing.com/problem/content/3305/


#include<iostream>
#include<unordered_map>
using namespace std;
const int N=1e5+10;
//存储运算数
int stk1[N];
int tt1;
//存储运算符
char stk2[N];
int tt2;
unordered_map<char,int> priority={{'+',1},{'-',1},{'*',2},{'/',2}};
void cal()
{
    int a=stk1[tt1--];
    int b=stk1[tt1--];
    char op=stk2[tt2--];
    int res;
    //注意a是第二个入栈的数，所以原算式顺序是b->a
    if(op=='+') res=a+b;
    if(op=='-') res=b-a;
    if(op=='*') res=b*a;
    if(op=='/') res=b/a;
    stk1[++tt1]=res;
}
int main()
{
    string s;
    cin>>s;
    for(int i=0;i<s.size();i++)
    {
        //整数判断
        if(isdigit(s[i]))
        {
            int x=0,j=i;
            while(j<s.size()&& isdigit(s[j]))
            {
                x=x*10+s[j]-'0';
                j++;
            }
            stk1[++tt1]=x;
            /*关于i为什么是j-1，首先我们知道当s[j]是运算符时while循环停止，那么j就是运算符所在的下标
            那么j就是运算符所在的下标，完全可以说i=j，‘-1’则是因为在整个for循环中i会自增*/
            i=j-1;
        }else if(s[i]=='(')
        {
            stk2[++tt2]=s[i];
        }else if(s[i]==')')
        {
            while(stk2[tt2]!='(')
            {
                cal();
            }
            //完成运算操作后，stk2数组里还留着一个'('，需要remove
            tt2--;
        }else{
            //优先级比较，是否要对stk1内的数提取运算
            while(tt2&&priority[stk2[tt2]]>=priority[s[i]])
            {
                cal();
            }
            stk2[++tt2]=s[i];
        }
    }
    //stk2经历循环后必然还剩一个运算符
    while(tt2) cal();
    cout<<stk1[tt1]<<endl;
    return 0;
}