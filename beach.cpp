#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const long long INF = 1e18; // กำหนดค่า Infinity ให้สูงพอ

struct Edge {
    int to;
    int weight;
};

struct Node {
    int id;
    long long dist;
    
    // Operator overloading เพื่อให้ priority_queue เรียงจากน้อยไปมาก (Min-Heap)
    bool operator>(const Node& other) const {
        return dist > other.dist;
    }
};

void dijkstra(int start, int n, const vector<vector<Edge>>& adj) {
    vector<long long> dist(n + 1, INF);
    priority_queue<Node, vector<Node>, greater<Node>> pq;

    dist[start] = 0;
    pq.push({start, 0});

    while (!pq.empty()) {
        int u = pq.top().id;
        long long d = pq.top().dist;
        pq.pop();

        // ถ้าเจอระยะทางที่เคยบันทึกไว้ดีกว่าค่าที่ดึงออกมา ให้ข้ามไป (Optimization)
        if (d > dist[u]) continue;

        for (const auto& edge : adj[u]) {
            int v = edge.to;
            int w = edge.weight;

            // Relaxation: ถ้าเดินผ่าน u ไป v แล้วระยะทางสั้นลง ให้จดบันทึกใหม่
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({v, dist[v]});
            }
        }
    }

    // แสดงผลระยะทางจากจุดเริ่มไปยังทุกจุด
    for (int i = 1; i <= n; i++) {
        if (dist[i] == INF) cout << "Node " << i << ": Unreachable" << endl;
        else cout << "Node " << i << ": " << dist[i] << endl;
    }
}

int main() {
    int n, e; // n = จำนวนจุด, e = จำนวนเส้นทาง
    cin >> n >> e;

    vector<vector<Edge>> adj(n + 1);
    for (int i = 0; i < e; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        // adj[v].push_back({u, w}); // เปิดบรรทัดนี้ถ้าเป็นกราฟไม่มีทิศทาง
    }

    dijkstra(1, n, adj); // เริ่มเดินจากจุดที่ 1

    return 0;
}