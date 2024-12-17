#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5+5, LOG = __lg(MM);
int N, Q; vector<pair<int, int>> adj[MM];
int anc[LOG+1][MM]; int dep[MM]; pair<int, int> mx[LOG+1][MM];
pair<int, int> getFirstTwo(pair<int, int> a, pair<int, int> b){
    vector<int> v = {a.first, a.second, b.first, b.second};
    sort(v.rbegin(), v.rend());
    return {v[0], v[1]};
}

void dfs(int u, int par, int pw){
    dep[u] = dep[par] + 1; anc[0][u] = par; mx[0][u] = {pw, -1};
    for(int k = 1; k <= LOG; k++){
        anc[k][u] = anc[k-1][anc[k-1][u]];
        mx[k][u] = getFirstTwo(mx[k-1][u], mx[k-1][anc[k-1][u]]);
    }
    for(auto [v, w] : adj[u]){
        if(v == par) continue;
        dfs(v, u, w); 
    }
}

int LCA(int u, int v){
    if(dep[u] < dep[v]) swap(u, v);
    for(int k = LOG; k >= 0; k--){
        if(dep[anc[k][u]] >= dep[v]) u = anc[k][u];
    }
    if(u==v) return u;
    for(int k = LOG; k >= 0; k--){
        if(anc[k][u] != anc[k][v]) u = anc[k][u], v = anc[k][v];
    }
    return anc[0][u];
}

pair<int, int> qry(int u, int lca){
    pair<int, int> ret = {-1, -1};
    for(int k=LOG; k>=0; k--)
        if(dep[anc[k][u]] >= dep[lca]) ret = getFirstTwo(ret, mx[k][u]), u = anc[k][u];
    return ret;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N;
    for(int i=1, u, v, w; i<N; i++) {
        cin >> u >> v >> w; adj[u].push_back({v, w}); adj[v].push_back({u, w});
    }
    dfs(1, 0, 0); cin >> Q;
    for(int i = 1, u, v; i<=Q; i++){
        cin >> u >> v; int lca = LCA(u, v);
        cout << getFirstTwo(qry(u, lca), qry(v, lca)).second << "\n";
    }
}