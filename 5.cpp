#include<bits/stdc++.h>
using namespace std;

void heapify(vector<int>&a,int n,int i){
    int l=2*i+1,r=2*i+2,lg=i;
    if(l<n && a[l]>a[lg]) lg=l;
    if(r<n && a[r]>a[lg]) lg=r;
    if(lg!=i){
        swap(a[i],a[lg]);
        heapify(a,n,lg);
    }
}

void heapsort(vector<int>&a){
    int n=a.size();
    for(int i=n/2-1;i>=0;i--) heapify(a,n,i);
    for(int i=n-1;i>=0;i--){
        swap(a[0],a[i]);
        heapify(a,i,0);
    }
}

int main(){
    vector<int>a={5,3,8,1,2};
    heapsort(a);
    for(int x:a) cout<<x<<" ";
}
