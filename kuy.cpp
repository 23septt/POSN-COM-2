#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(nullptr)->sync_with_stdio(0);
    int k , n , m;
    cin >> k >> n >> m ;
    vector<vector<int>> adj(n+1);
    for(int i=0;i<m;i++){
        int u,v ;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    vector<int> dist(n+1,-1);
    queue<int> q;
    q.push(1);
    dist[1]=0;
    int mx=1;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        if(dist[u]<k){
            for(int v : adj[u]){
                if(dist[v]==-1) {
                    dist[v]=dist[u]+1;
                    if(v>mx) mx=v;
                    q.push(v);
                }
            }
        }
    }
    cout << mx;
}