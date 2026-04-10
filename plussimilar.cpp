#include <bits/stdc++.h>
using namespace std;

map<int,int> m;
int main(){
    int n,x,i,j,a,b;
    cin >> n >> x;
    for(i=0;i<n+x;i++){
        cin >> a >> b;
        m[a]+=b;
    }
    for(auto [a,b] : m){
        cout << a << " " << b << "\n";
    }
}