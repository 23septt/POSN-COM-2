#include <bits/stdc++.h>
using namespace std;

int di[4]={1,-1,0,0};
int dj[4]={0,0,1,-1};

int main(){
    int n,m,i,j,x,y,ans;
    cin >> n >> m;
    vector<vector<int>> v(n , vector<int>(m));
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            cin >> v[i][j];
        }
    }
queue<pair<int,int>> q;
for(x=0;x<n;x++){
    for(y=0;y<m;j++){
        if(v[i][j]==1){
            q.push({i,j});
            while(!q.empty()){
                pair<int,int> front;
                q.pop();
                int m=front.first;
                int n=front.second;
                for(int d=0;d<4;d++){
                    int ni = i + di[d];
                    int nj = j + dj[d];
                    if(ni >= 0 && ni <n && nj >= 0 && ni <m && v[ni][nj]==1){
                        q.push({ni,nj});
                        v[ni][nj]=0;
                    }
                }

            }
        }
    }
}

}