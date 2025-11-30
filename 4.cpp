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
        g[v].push_back({u,w});
    }
    vector<int> vis(n,0);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    pq.push({0,0});
    int cost=0;
    while(!pq.empty()){
        auto [w,u]=pq.top(); pq.pop();
        if(vis[u]) continue;
        vis[u]=1;
        cost+=w;
        cout<<u<<" "<<w<<endl;
        for(auto &p:g[u]){
            pq.push({p.second,p.first});
        }
    }
    cout<<cost;
}
