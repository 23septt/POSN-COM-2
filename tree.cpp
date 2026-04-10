#include<bits/stdc++.h>
using namespace std;

int di[4] = {1, -1, 0, 0};
int dj[4] = {0, 0, -1, 1};

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> mat(n, vector<int>(m));
    vector<vector<bool>> v(n, vector<bool>(m, 0));
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < m ; j++) {
            cin >> mat[i][j];
        }
    }
    
    int ans = 0,count = 0;
    for (int i = 0 ; i < n ; i++) {
        for (int j = 0 ; j < m ; j++) {
            if (mat[i][j] == 1) {
                ans++;
                queue<pair<int, int>> bag;
                bag.push({i, j});
                v[i][j] = 1;
                while(!bag.empty()) {
                    pair<int, int> front = bag.front();
                    bag.pop();
                    int i = front.first;
                    int j = front.second;
                    for (int d = 0 ; d < 4 ; d++) {
                        int ni = i + di[d];
                        int nj = j + dj[d];
                        if (ni >= 0 && ni < n && nj >= 0 && nj < m && !v[ni][nj] && mat[ni][nj] == 1) {
                            bag.push({ni, nj});
                            v[ni][nj] = 1;
                            mat[ni][nj] = 0;
                        }
                    }
                }
            }
        }
    }
    cout << ans;
}