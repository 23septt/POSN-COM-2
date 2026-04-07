#include<bits/stdc++.h>
using namespace std;
vector<int> memo(100, -1);
int fiboTD(int n)
{
    if (n <= 0)
        return -1;
    if (memo[n] != -1)
        return memo[n];
    if (n <= 2)
        memo[n] = 1;
    else
        memo[n] = fiboTD(n - 1) + fiboTD(n - 2);
    return memo[n];
}
int fiboBU(int n){
    vector<int> dp(n+1, 0);
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2 ; i <= n ; i++) {
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}

int main() {
    cin.tie(0)->sync_with_stdio;
    int n;
    cin >> n;
    cout << fiboTD(n);
}
