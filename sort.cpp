#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,i;
    cin >> n;
    vector<pair<string,int>> v(n);
    for (i=0;i<n;i++){
        cin >> v[i].first >> v[i].second ;
    }
    sort(v.begin(),v.end(), [](auto a , auto b){
        return a.second > b.second;
    });
    for(auto e : v){
        cout << e.first << endl;
    }
}
