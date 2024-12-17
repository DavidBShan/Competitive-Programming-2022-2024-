#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5+5, LOG = log2(2*MM); vector<int> euler; int dep[MM], in[MM], dis[MM]; 
vector<pair<int, int>> adj[MM]; pair<int, int> st[2*MM][LOG+1];
void dfs(int u, int pre){
    in[u] = euler.size(); euler.push_back(u);
    for(auto [v, w] : adj[u]){
        if(v != pre) {
            dep[v] = dep[u] + 1; dis[v] = dis[u] + w;
            dfs(v, u);
            euler.push_back(u);
        }
    }
}

int lca(int u, int v){
    int lft = min(in[u], in[v]), rit = max(in[u], in[v]);
    int k = log2(rit - lft + 1);
    return min(st[lft][k], st[rit-(1<<k)+1][k]).second;
}

int dist(int u, int v){
    return dis[u] + dis[v] - 2*dis[lca(u, v)];
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int N, D; cin >> N >> D;
    for(int i = 0; i < N-1; i++){
        int a, b, c; cin >> a >> b >> c;
        adj[a].push_back({b, c}); adj[b].push_back({a, c});
    }
    dfs(1, -1); int M = euler.size(), LOG1 = log2(M);
    for(int i=0; i<M; i++) st[i][0] = {dep[euler[i]], euler[i]};
    for(int k=1; k<=LOG; k++)
        for(int i=0; i+(1<<k)-1 <M; i++)
            st[i][k] = min(st[i][k-1], st[i+(1<<k-1)][k-1]);
    int a = 1, b = 1; long long dp1 = 0, dp2 = 0;
    for(int d=1, x, y; d<=D; d++) {
        cin >> x >> y;
        long long dx = min(dp1 + dist(a, y) + dist(y, x), dp2 + dist(b, y) + dist(y, x));
        long long dy = min(dp1 + dist(a, x) + dist(x, y), dp2 + dist(b, x) + dist(x, y));
        dp1 = dx;  dp2 = dy;  a = x; b  = y;
    }
    cout << min(dp1, dp2) << "\n";
}