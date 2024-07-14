//https://www.acwing.com/problem/content/792/


#include<iostream>
using namespace std;
double n;
const double eps=1e-8;
int main()
{
    scanf("%lf",&n);
    double l=-10000,r=10000;
    while((r-l)>eps){
        double mid=(l+r)/2;
        if(mid*mid*mid>=n) r=mid;
        else l=mid;
    }
    printf("%.6lf",l);
    return 0;
}