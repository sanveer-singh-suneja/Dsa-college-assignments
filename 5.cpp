#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<pair<int,int>>> g(n);
    while(m--){
        int u,v,w;
        cin>>u>>v>>w;
        g[u].push_back({v,w});
    }
    int src;
    cin>>src;
    vector<int> dist(n,1e9);
    dist[src]=0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({0,src});
    while(!pq.empty()){
        auto [d,u]=pq.top(); pq.pop();
        if(d!=dist[u]) continue;
        for(auto &p:g[u]){
            int v=p.first,w=p.second;
            if(dist[u]+w<dist[v]){
                dist[v]=dist[u]+w;
                pq.push({dist[v],v});
            }
        }
    }
    for(int i=0;i<n;i++) cout<<dist[i]<<" ";
}
