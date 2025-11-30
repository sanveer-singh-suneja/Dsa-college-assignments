#include<bits/stdc++.h>
using namespace std;

struct MaxHeap{
    vector<int>a;

    void push(int x){
        a.push_back(x);
        int i=a.size()-1;
        while(i>0 && a[(i-1)/2]<a[i]){
            swap(a[i],a[(i-1)/2]);
            i=(i-1)/2;
        }
    }

    int top(){
        if(a.empty()) return -1;
        return a[0];
    }

    void pop(){
        if(a.empty()) return;
        a[0]=a.back();
        a.pop_back();
        int n=a.size();
        int i=0;
        while(true){
            int l=2*i+1,r=2*i+2,lg=i;
            if(l<n && a[l]>a[lg]) lg=l;
            if(r<n && a[r]>a[lg]) lg=r;
            if(lg!=i){
                swap(a[i],a[lg]);
                i=lg;
            } else break;
        }
    }
};

int main(){
    MaxHeap pq;
    pq.push(10);
    pq.push(5);
    pq.push(20);
    pq.push(1);

    cout<<pq.top()<<endl;
    pq.pop();
    cout<<pq.top()<<endl;
}
