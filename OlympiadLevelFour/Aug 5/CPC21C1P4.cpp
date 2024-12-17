#include <bits/stdc++.h>
using namespace std;
const int MM = 3*1e5+5;
int vis[MM]; vector<int> adj[MM];
void dfs(int val, int label){
    vis[val] = label;
    for(int v : adj[val])
        if(vis[v] == 0) dfs(v, label);
}

int main(){
    int N, M; cin >> N >> M;
    for(int i = 0, u, v; i< M;i++){
        cin >> u >> v; adj[v].push_back(u);
    }
    for(int i = N; i>0; i--){
        if(vis[i]==0) dfs(i, i);
    }
    for(int i = N; i >0; i--){
        if(vis[i]>i) {cout << i << " " << vis[i] << endl; return 0;}
    }
    cout << "-1";
}