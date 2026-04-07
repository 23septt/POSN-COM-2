#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int n, m;
    if (!(cin >> n >> m)) return 0;

    vector<vector<int>> temp(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> temp[i][j];
        }
    }

    vector<vector<int>> min_shock(n, vector<int>(m, INF));
    

    priority_queue<pair<int, pair<int, int>> , vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

    min_shock[0][0] = 0;
    pq.push({0, {0, 0}});

    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};

    while (!pq.empty()) {
        int d = pq.top().first;
        int r = pq.top().second.first;
        int c = pq.top().second.second;
        pq.pop();

        if (d > min_shock[r][c]) continue;
        
        if (r == n - 1 && c == m - 1) {
            cout << d << "\n";
            return 0;
        }

        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (nr >= 0 && nr < n && nc >= 0 && nc < m) {
                int diff = abs(temp[r][c] - temp[nr][nc]);
                int current_path_shock = max(d, diff);

                if (current_path_shock < min_shock[nr][nc]) {
                    min_shock[nr][nc] = current_path_shock;
                    pq.push({current_path_shock, {nr, nc}});
                }
            }
        }
    }
    return 0;
}