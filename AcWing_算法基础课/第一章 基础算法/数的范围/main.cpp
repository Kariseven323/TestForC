/*https://www.acwing.com/problem/content/791/*/


#include<iostream>

using namespace std;

const int N=1e5+10;
int n,q;
int a[N];

int main()
{
    scanf("%d %d",&n,&q);

    for(int i=0;i<n;i++) scanf("%d",&a[i]);

    while(q--) {

        int x;
        scanf("%d",&x);

        int l = 0, r = n - 1;

        while (l < r) {

            int mid = (l + r) >> 1;

            if (x<=a[mid]) r=mid;
            else l=mid+1;
        }//前半段

        if(a[l]!=x) printf("-1 -1\n");
        else{

            printf("%d ",l);

            int l=0,r=n-1;

            while(l<r){

                int mid = (l+r+1)>>1;

                if(a[mid]<=x) l=mid;
                else r = mid-1;
            }
            printf("%d\n",r);
        }
    }//后半段
    return 0;
}