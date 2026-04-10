#include <bits/stdc++.h>
using namespace std;

int INF=1e9;

void stp(int v,vector<vector<int>>& dp,int i,int j,int k){
    for (k = 0; k < v; k++) {
        for (i = 0; i < v; i++) {
            for (j = 0; j < v; j++) {
                if (dp[i][k] != INF && dp[k][j] != INF) {
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
                }
            }
        }
    }
}

int main(){
    cin.tie(nullptr)->sync_with_stdio(0);
    int v;
    cin >> v;
    vector<vector<int>> dp(v,vector<int>(v));
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            cin >> dp[i][j];
        }
    }
    stp(v,dp,0,0,0);
    int mx=0;
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            mx=max(mx,dp[i][j]);
        }
    }
    cout << mx;
} 