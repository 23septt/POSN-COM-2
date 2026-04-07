#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(nullptr)->sync_with_stdio(0);
    unordered_map<char,int> mapp;
    string in;
    cin >> in;
    for(int i=0;i<in.size();i++){
        if(in[i]>=97) in[i]-=32;
        if(in[i] <65 || in[i] > 90) {
            cout << "F" ;
            return 0;
        }
        mapp[in[i]]++;
        if(mapp[in[i]]==2){
            cout << "F" ;
            return 0;
        }
    }
    cout << "T";

}
