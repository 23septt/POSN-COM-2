#include <bits/stdc++.h>
using namespace std;

int n,m;
vector<vector<int>> dp;
vector<vector<int>> path;

int solve(int i,int j,vector<vector<int>> &path){
    if(i==n-1 && j==m-1) return 1;
    if(dp[i][j]!=-1) return dp[i][j];
    int way=0;
    if(i+1<n && path[i+1][j]==0 ){
        way+=solve(i+1,j,path);
    }
    if(j+1<m && path[i][j+1]==0 ){
        way+=solve(i,j+1,path);
    }
    return dp[i][j]=way;
}

int main(){
    cin >> n >> m;
    dp.resize(n,vector<int>(m,-1));
    path.resize(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> path[i][j];
        }
    }
    cout << solve(0,0,path);
}