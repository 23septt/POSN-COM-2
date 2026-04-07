#include <bits/stdc++.h>
using namespace std;

int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dest, int limit_k) {
    vector<vector<int>> adj(n, vector<int>(n, 1e9));
    for (auto f : flights) {
        int u = f[0];
        int v = f[1];
        int w = f[2];
        adj[u][v] = w;
        adj[v][u] = w;
    }
    for (int i = 0 ; i < n ; i++) adj[i][i] = 0;
    for (int k = 0 ; k < limit_k ; k++) {
        for (int i = 0 ; i < n ; i++) {
            if (i == k) continue;
            for (int j = 0 ; j < n ; j++) {
                if (i == j) continue;
                adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
            }
        }
    }
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < n ; j++) {
            cout << adj[i][j] << ' ';
        }
        cout << endl;
    }
    return adj[src][dest];
}

int main(){
    cin.tie(nullptr)->sync_with_stdio(0);
    
}