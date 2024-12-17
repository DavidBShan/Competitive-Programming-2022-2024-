#include <bits/stdc++.h>
using namespace std;
const long long MM = 4e5+3;
long long n, dis[MM], cnt[MM], diameter;vector<long long> adj[MM]; long long num;

void dfs(long long u, long long par){
    dis[u] = 0; cnt[u] = 1;
    for(long long v: adj[u]) {
        if(v==par) continue;
        dfs(v, u);
        if(dis[v] + dis[u] + 1 > diameter){
            diameter = dis[v] + dis[u] + 1;
            num = cnt[v] * cnt[u];
        } else if(dis[v] + dis[u] + 1 == diameter) num += cnt[v] * cnt[u];
        if(dis[v] + 1 > dis[u]){
            dis[u] = dis[v] + 1;
            cnt[u] = cnt[v];
        } else if(dis[v] + 1 == dis[u]) cnt[u] += cnt[v];
    }
}.

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for(long long i = 1, u, v; i < n; i++){
        cin >> u >> v; adj[u].push_back(v); adj[v].push_back(u);
    }
    dfs(1, 0);
    cout << diameter + 1 << " " << num;
}