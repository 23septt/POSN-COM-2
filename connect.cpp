#include <bits/stdc++.h>
using namespace std;

map<int,int> parent;

int find(int x){
    if (parent[x] == 0) return parent[x] = x;
    if(parent[x]==x) return x;
    return parent[x]=find(parent[x]);
}
int main(){
    cin.tie(nullptr)->sync_with_stdio(0);
    int n;
    cin >> n;
    int count =0;
    for(int i=0;i<n;i++){
        int s,d;
        cin >> s >> d;
        int rs=find(s);
        int rd=find(d);
        if(rs!=rd){
            parent[rs]=rd;
            count++;
        }
    }
    cout << count << endl;
}