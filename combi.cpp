#include <bits/stdc++.h>
using namespace std;

int n,k;
int count=0;
int x=1;

void combi(vector<int>& x){
    int back=0;
    if(k == x.size()){
    for(auto i : x){
        cout << i << " " ;
    }
    cout << "\n";
    return;
    }
    if(!x.empty()) {
        back=x.back();
    }
    for(int i=back+1;i<=n;i++){
        x.push_back(i);
        combi(x);
        x.pop_back();
    }
}

int main(){
    vector<int> x;
    cin >> n >> k;
    combi(x);
}