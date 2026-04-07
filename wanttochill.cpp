#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

void findPath(int j, vector<int>& parent, vector<int>& ans) {
    if (j == -1) return;
    findPath(parent[j], parent, ans);
    ans.push_back(j);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int m, start;
    if (!(cin >> m >> start)) return 0;

    vector<pair<int, int>> adj[10005]; 
    int max_node = start;

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        max_node = max({max_node, u, v}); 
    }

    vector<int> dist(max_node + 1, INF);
    vector<int> parent(max_node + 1, -1);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (d > dist[u]) continue;

        for (auto& edge : adj[u]) {
            int v = edge.first;
            int weight = edge.second;

            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                parent[v] = u;
                pq.push({dist[v], v});
            }
        }
    }

    for (int i = 0; i <= max_node; i++) {
        if (i == start || dist[i] == INF) continue;

        vector<int> path;
        findPath(i, parent, path);
        
        for (int j = 0; j < path.size(); j++) {
            cout << path[j] << (j == path.size() - 1 ? "" : " ");
        }
        cout << "\n";
    }

    return 0;
}