#include <bits/stdc++.h>
using namespace std;

vector<string> in;
vector<int> parent;
vector<pair<char,char>> no;

int find(int x){
    if(parent[x]==x) return x;
    return parent[x]=find(parent[x]);
}

void unite(int x,int y){
    int px=find(x);
    int py=find(y);
    if(px!=py){
        parent[px]=py;
    }
}

int main(){
    cin.tie(nullptr)->sync_with_stdio(0);
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        string temp;
        cin >> temp;
        in.push_back(temp);
    }
    for(int i = 0 ; i < 26 ; i++) {
        parent.push_back(i);
    }
    for(int i=0;i<n;i++){
          if(in[i][1] == '!'){
            no.push_back({in[i][0],in[i][3]});
          }
          else unite(in[i][0]-'a',in[i][3]-'a');
    }
    // for(int i=0;i<parent.size();i++){
    //     cout << (char)(i+'a') << ' ';
    //     if (find(i) >= 10) cout << ' ';
    // }
    // cout << endl;
    // for(int i=0;i<parent.size();i++){
    //     cout << find(i) << ' ';
    // }

    for(auto p : no){
        if (find(p.first-'a') == find(p.second-'a')) {
            cout << "false";
            return 0;
        }
    }
    cout << "true";
}