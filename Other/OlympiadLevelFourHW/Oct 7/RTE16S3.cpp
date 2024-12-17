#include <bits/stdc++.h>
using namespace std;
const int LOG = 18, MM = 6005;
int N, Q; vector<pair<int, int>> adj[MM]; vector<int> euler;
int dep[MM], in[MM];long long dis[MM]; pair<int, int> st[2*MM][LOG];
void dfs(int par, int u){
    in[u] = euler.size(); euler.push_back(u);
    for(int i = 0; i < adj[u].size(); i++){
        int v = adj[u][i].first, w = adj[u][i].second;
        if(v == par) continue;
        dep[v] = dep[u] + 1; dis[v] = dis[u] + w;
        dfs(u, v); euler.push_back(u);
    }
}
int lca(int u, int v){
    int l = in[u], r = in[v];
    if(l > r) swap(l, r);
    int k = log2(r - l + 1);
    return min(st[l][k], st[r-(1<<k)+1][k]).second;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N;
    for(int i = 0, a, b, w; i < N-1; i++){
        cin >> a >> b >> w;
        adj[a].push_back({b, w}); adj[b].push_back({a, w});
    }
    memset(dis, 0, sizeof(dis)); 
    dfs(-1, 0); int M = euler.size();
    for(int i = 0; i < M; i++) st[i][0] = {dep[euler[i]], euler[i]};
    for(int i = 1; i < LOG; i++){
        for(int j = 0; j + (1<<i) <= M; j++){
            st[j][i] = min ( st[j][i-1] ,  st[j+(1<<i-1)][i-1]);
        }
    }
    cin >> Q;
    for(int k = 0, u, v; k < Q; k++){
        cin >> u >> v;
        cout << dis[u] + dis[v] - 2*dis[lca(u, v)] << "\n";
    }
}
