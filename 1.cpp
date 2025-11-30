#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> g(n);
    while(m--){
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int start;
    cin>>start;
    vector<int> vis(n,0);
    queue<int> q;
    q.push(start);
    vis[start]=1;
    while(!q.empty()){
        int u=q.front(); q.pop();
        cout<<u<<" ";
        for(int v:g[u]){
            if(!vis[v]){
                vis[v]=1;
                q.push(v);
            }
        }
    }
}
