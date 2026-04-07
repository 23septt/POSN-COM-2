#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(nullptr)->sync_with_stdio(0);
    int n,m;
    cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    cin >> m;
    int q;
    for(int i=0;i<m;i++){
        cin >> q;
        if(binary_search(a.begin(),a.end(),q)) cout << "Found";
        else cout << "Not Found";
        cout << "\n";
    }
}