#include <bits/stdc++.h>
using namespace std;
const int MM = 1e7+3;
vector<int> room[MM];int M, N; bool visited[MM];
void dfs(int val){
    if(visited[val]) return;
    visited[val] = true;
    if(val==M*N){
        cout << "yes" << "\n";
        exit(0);
    }
    for(int i = 0; i < room[val].size(); i++){
        if(!visited[room[val][i]]) dfs(room[val][i]);
    }
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> M >> N;  
    for(int i = 1; i <= M; i++){
        for(int j = 1, temp; j <= N; j++){
            cin >> temp; room[i*j].push_back(temp);
        }
    }
    dfs(1);
    cout << "no" << "\n";
}