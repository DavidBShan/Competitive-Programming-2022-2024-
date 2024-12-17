#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5+5;
int n, m, k, color[MM]; vector<int> adj[MM]; bool vis[MM];

void dfs(int u){
    vis[u] = 1; vector<bool> cont(k+1);
    for(int v : adj[u]){
        if(!vis[v]) dfs(v);
        cont[color[v]] = 1;
    }
    for(int i = 1; i <= k; i++){
        if(!cont[i]) { color[u] = i; break; }
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for(int i = 1, u, v; i <= m; i++){
        cin >> u >> v; adj[u].push_back(v); adj[v].push_back(u);
    }
    for(int i = 1; i <= n; i++) k = max(k, (int)adj[i].size());
    if(k % 2 == 0) k++;
    cout << k << endl;
    for(int i = 1; i <= n; i++){
        if(adj[i].size() < k){
            dfs(i); break;
        }
    }
    for(int i = 1; i <= n; i++) cout << color[i] << "\n";
}