#include <bits/stdc++.h>
using namespace std;
const int MM = 2e5+5;
int n, m; char ans[MM]; map<int, vector<pair<int ,int>>> adj;
int vis[MM];

void dfs(int cur, int par, char ch){
    if(vis[cur]) return;
    vis[cur] = 1;
    for(auto [u, i]: adj[cur]){
        if(u==par || vis[u]) continue;
        ans[i] = ch;
        dfs(u, cur, ch=='B'?'R':'B');
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int a, b; cin >> a >> b;
        adj[a].push_back({b, i});
        adj[b].push_back({a, i});
    }
    for(int i = 1; i <= m; i++) ans[i] = 'G';
    for(int i = 1; i <= n; i++){
        if(!vis[i]) dfs(i, 0, 'B');
    }
    for(int i = 1; i <= m; i++) cout << ans[i];
}