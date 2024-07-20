#include<iostream>
using namespace std;
int temp[100010];
int q[100010];
int n;
int res=0;
void merge_sort(int q[],int l,int r){
    if(l>=r)return ;
    int mid=(l+r)/2;
    merge_sort(q,l,mid),merge_sort(q,mid+1,r);
    int k=0,i=l,j=mid+1;
    while(i<=mid&&j<=r){
        if(q[i]<=q[j])
        {
            temp[k++]=q[i++];
        }
        else{
            temp[k++]=q[j++];
            res+=(mid-i+1);  //注意这里是mid-i+1，而不是j-i+1
        }
    }
    while(i<=mid)
        temp[k++]=q[i++];
    while(j<=r)
        temp[k++]=q[j++];

    for(i=l,j=0;i<=r;i++,j++){
        q[i]=temp[j];
    }
}
int main(){
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>q[i];
    }
    merge_sort(q,0,n-1);
    cout<<res;
    return 0;
}