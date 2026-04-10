#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>> nor,s(2);
int main(){
    cin.tie(nullptr)->sync_with_stdio(0);
    int n;
    cin >> n;
    nor.resize(n);
    for(int i=0;i<n;i++){
        cin >> nor[i].first >> nor[i].second;
    }
    cin >> s[0].first >> nor[0].second;
    for(int i=0;i<n;i++){
        if(nor[i].first<=s[0].first && s[0].first<=nor[i].second){
            cout << nor[i].first;
        }
        if(nor[i].second<=s[0].second && s[0].second>=nor[i].second){
            cout << nor[i].first;
        }
    }
    
}