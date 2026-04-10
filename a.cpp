#include <bits/stdc++.h>
using namespace std;

int main(){
    int TEMP=0;
    deque<int> s;
    while(TEMP>=0){
        cin>>TEMP;
        s.push_back(TEMP);
        sort(s.begin(),s.end(), greater<int>());
        if(s.size()==5){
            s.pop_back();
        }
    }
    for(int i=0;i<4;i++){
        cout<< s[i] << " ";
    }
}
