#include<bits/stdc++.h>
using namespace std;

struct DSU{
    vector<int> p,r;
    DSU(int n){p.resize(n); r.assign(n,0); iota(p.begin(),p.end(),0);}
    int find(int x){return p[x]==x?x:p[x]=find(p[x]);}
    void unite(int a,int b){
        a=find(a); b=find(b);
        if(a!=b){
            if(r[a]<r[b]) swap(a,b);
            p[b]=a;
            if(r[a]==r[b]) r[a]++;
        }
    }
};

int main(){
    int n,m;
    cin>>n>>m;
    vector<array<int,3>> edges;
    while(m--){
        int u,v,w;
        cin>>u>>v>>w;
        edges.push_back({w,u,v});
    }
    sort(edges.begin(),edges.end());
    DSU d(n);
    int cost=0;
    for(auto &e:edges){
        int w=e[0],u=e[1],v=e[2];
        if(d.find(u)!=d.find(v)){
            d.unite(u,v);
            cost+=w;
            cout<<u<<" "<<v<<" "<<w<<endl;
        }
    }
    cout<<cost;
}
