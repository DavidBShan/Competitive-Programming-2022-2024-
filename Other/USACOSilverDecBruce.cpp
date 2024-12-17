#include <bits/stdc++.h>
using namespace std;
const long long MM = 2e5+2;
long long N, h[MM], sz[MM]; long long sum[MM], avg; vector<array<long long, 3>> up, dn; vector<long long> adj[MM];
void dfs(long long u, long long par){
    sz[u] = 1; sum[u] = h[u];
    for(long long v: adj[u]){
        if(v==par) continue;
        dfs(v, u); sz[u]+=sz[v]; sum[u]+=sum[v];
    }
    if(sum[u] > sz[u]*avg) up.push_back({u, par, sum[u]-sz[u]*avg});
    if(sum[u] < sz[u]*avg) dn.push_back({par, u, sz[u]*avg-sum[u]});

}
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N;
    for(long long i = 1; i<=N; i++) {cin >> h[i]; avg+=h[i];}
    avg/=N;
    for(long long i = 1, u, v; i < N; i++){
        cin >> u >> v; adj[u].push_back(v); adj[v].push_back(u);
    }
    dfs(1, 0);
    cout << up.size() + dn.size() << "\n";
    reverse(dn.begin(), dn.end());
    for(array<long long, 3> a: up) cout << a[0] << " " << a[1] << " " << a[2] << "\n";
    for(array<long long, 3> a: dn) cout << a[0] << " " << a[1] << " " << a[2] << "\n";
}