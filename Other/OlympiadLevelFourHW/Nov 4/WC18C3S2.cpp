#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5+5;
int N, K, F, mx, cnt[MM], dep[MM]; bool gym[MM]; vector<int> adj[MM];
void dfs(int u, int p){
    cnt[u] = 0;
    for(int v: adj[u]){
        if(v == p) continue;
        dep[v] = dep[u] + 1;
        dfs(v, u);
        if(gym[v]) { cnt[u] += cnt[v]+1; gym[u]=true; }
    }
    if(gym[u]) mx = max(mx, dep[u]);
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> K >> F;
    for(int i = 1; i <= K; i++){
        int temp; cin >> temp; gym[temp] = true;
    }
    for(int i = 1; i < N; i++){
        int u, v; cin >> u >> v; adj[u].push_back(v); adj[v].push_back(u);
    }
    dfs(1, 0); int noDragon = 2*cnt[1] - mx;
    gym[F] = true; dfs(1, 0); int dragon = cnt[1];
    cout << min(dragon, noDragon) << endl;
}