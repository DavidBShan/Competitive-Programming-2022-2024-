#include <bits/stdc++.h>
using namespace std;
const int MM = 100005, LOG = 17;
vector<int> adj[MM]; int N, Q, e[MM], cnt = 0, in[MM], out[MM], dep[MM], bit[2*MM], anc[LOG][MM];
void dfs(int u, int pa){
    dep[u] = dep[pa] + 1; anc[0][u] = pa;  in[u] = ++cnt;
    for(int k=1; k<LOG; k++) anc[k][u] = anc[k-1][anc[k-1][u]];
    for(int v : adj[u])
        if(v != pa) dfs(v, u);
    out[u] = ++cnt;
}

void upd(int pos, int val){ for(int i = pos; i <= 2*MM; i+=i&-i) bit[i]^=val;}

int qry(int pos){
    int ret = 0;
    for(int i = pos; i >0; i-=i&-i) ret^=bit[i]; 
    return ret;
}

int LCA(int u, int v){
    if(dep[u] < dep[v]) swap(u, v);
    for(int k=LOG-1; k>=0; k--)
        if(dep[anc[k][u]] >= dep[v]) u = anc[k][u];
    if(u == v) return u;
    for(int k=LOG-1; k>=0; k--)
        if(anc[k][u] != anc[k][v]) u = anc[k][u], v = anc[k][v];
    return anc[0][u];
}

int main(){
    cin >> N >> Q;
    for(int i = 1; i <= N; i++) cin >> e[i];
    for(int i = 1; i <= N-1; i++){
        int u, v; cin >> u >> v;
        adj[u].push_back(v); adj[v].push_back(u);
    }
    dfs(1, 0);
    for(int i = 1; i <= N; i++) {upd(in[i], e[i]); upd(out[i], e[i]);}
    for(int i = 1, q; i <= Q; i++){
        int u, v; cin >> q >> u >> v;
        if(q==1) {upd(in[u], e[u]^v); upd(out[u], e[u]^v); e[u] = v;}
        else{cout << (qry(in[u])^qry(in[v])^e[LCA(u, v)])<<"\n";}
    }
}