#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>> thing;
vector<int> ans,temp;
int maxx=0;
int n,c;
vector<vector<int>> dp;
void solve(vector<pair<int,int>> thing , int n , int c , int index , int v){
    if(n == index){
        if(v >= maxx){
        maxx=v;
        ans = temp;
        }
        return;
    }
    if(c-thing[index].second >= 0){
        temp.push_back(index);
        solve(thing,n,c-thing[index].second,index+1,v+thing[index].first);
        temp.pop_back();
    }
    solve(thing,n,c,index+1,v);
}
int main(){
    cin >> n >> c;
    vector<pair<int,int>> input(n);
    for(int i=0;i<n;i++){
        cin >> input[i].first;
    }
    for(int i=0;i<n;i++){
        cin >> input[i].second;
    }
    solve(input,n,c,0,0);

    cout << maxx << endl;
    for(auto i : ans){
        cout << i+1 << " " ;
    }
} 