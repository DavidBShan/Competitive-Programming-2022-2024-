#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    pair<int, int> dir[4] = {{1,0}, {0, 1}, {-1, 0}, {0, -1}};
    int W, L; cin >> W >> L; 
    int ans = 0; bool visited[W][L];
    char temp;
    for(int i = 0; i < W; i++){
        for(int j = 0; j< L; j++){
            cin >> temp;
            visited[i][j] = (temp=='#')?false:true;
        }
    }
    //queue<pair<int, int>> q;
    for(int i = 0; i < W; i++){
        for(int j = 0; j< L; j++){
            if(visited[i][j]==true) continue;
            visited[i][j] = true; ans++;
                for(int a = 0; a < 4; a++){
                    if(i+dir[a].first<0 || i+dir[a].first>=W ) continue;
                    if(j+dir[a].second<0 || j+dir[a].second>=L ) continue;
                    if(visited[i+dir[a].first][j+dir[a].second]==false){
                        visited[i+dir[a].first][j+dir[a].second]=true;
                        break;
                    }
                }
            //}
        }
    }
    cout << ans;
}