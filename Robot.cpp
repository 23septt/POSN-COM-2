#include <bits/stdc++.h>
using namespace std;

vector<int> dp(1,-1);

int loop(int n,vector<int> temp){
    if(n>=temp.size()){
        return 0;
    }
    if(dp[n]!=-1){
        return dp[n];
    }
    dp[n]=temp[n]+loop(n+temp[n], temp);
    return dp[n];

}
int main(){
    int n,x,maxx;
    cin >> n;
    dp.resize(n);
    vector<int> temp(n);
    for(int i=0;i<n;i++){
        cin >> temp[i] ;
    }
    for(int i=0;i<n;i++){
        maxx=max(maxx,loop(i,temp));
    }
    cout << maxx;  
}