#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pi;
const int MM = 5e5+3;
int N, dis[MM], pre[MM], dia, far, rad; vector<pi> adj[MM];
void dfs(int u, int par, int d){
    pre[u] = par; dis[u] = d;
    if(dis[u]>dia){far = u; dia = dis[u];}
    for(pi e: adj[u]){
        int v = e.first, w = e.second;
        if(v != par) dfs(v,u,d+w);
    }
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    for(int i = 1, u, v, w; i < N;i++){
        cin >> u >> v >> w;
        adj[u].push_back({v,w}); adj[v].push_back({u,w});
    }
    dfs(1,-1,0); dia = 0; dfs(far,-1,0);
    rad = 1e9;
    for(int u = far;u!=-1;u=pre[u]){
        rad = min(rad, max(dia-dis[u],dis[u]));
    }
    cout << dia << "\n" << rad << "\n";
}