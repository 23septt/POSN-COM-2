#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(nullptr)->sync_with_stdio(0);
    int c,p,d;
    cin >> c >> p >> d;
    map<string,vector<string>> adj;
    map<string,int> risk;
    set<string> name;
    string poison;
    for(int i=0;i<c;i++){
        string tempA,tempB;
        cin >> tempA >> tempB;
        name.insert(tempA);
        name.insert(tempB);
        adj[tempA].push_back(tempB);
        adj[tempB].push_back(tempA);
    }
    for(auto n : name) risk[n]=1e9;
    queue<string> q;
    for(int i=0;i<p;i++){
        cin >> poison;
        risk[poison] = 1;
        q.push(poison);
    }

    while(!q.empty()){
        string cur = q.front();
        q.pop();

        for(string connect : adj[cur]){
            if(risk[connect] > risk[cur] + 1){
                risk[connect] = risk[cur] + 1;
                q.push(connect);
            }
        }
    }
    int count=0;
    cout << endl;
    for(auto a : name){
        if(risk[a]==d) count++;
    }
    cout << count ;
}