#include <bits/stdc++.h>
using namespace std;


bool koy(int c,int n,vector<int> p,vector<int> s,vector<int> e){
    c-=p[0];
    for(int i=0;i<n;i++){
        if(s[i+1]<e[i]) c-=p[i+1];
        if(e[i]<s[i+1]) c+=p[i+1];
        if(c<0) return false;
        }
        return true;
}

int main(){
    cin.tie(nullptr)->sync_with_stdio(0);
    int c,n;
    cin >> c >> n; 
    vector<int> p(n),s(n),e(n);
    // sort(p.begin(),p.end());
    // sort(s.begin(),s.end());
    // sort(e.begin(),e.end());
    for(int i=0;i<n;i++){
        cin >> p[i] >> s[i] >> e[i];
    }
    if(koy(c,n,p,s,e)) cout << "YES";
    else cout << "NO";
}