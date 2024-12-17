#include <bits/stdc++.h>
using namespace std;
const int MM = 2003;
vector<array<int, 3>> adj[MM]; vector<array<int, 5>> edge; bool good[MM]; long long dist[MM];
void dijk(int start, int end){
    priority_queue<pair<long, long>, vector<pair<long, long>>, greater<pair<long, long>>> q;
    memset(dist, 0x3f, sizeof dist);
    dist[start] = 0;  q.push({0, start});
    while(!q.empty()) {
        auto [d, u] = q.top(); q.pop();
        if(d > dist[u]) continue;
        for(auto [v, w, i] : adj[u]){
            if(good[i] && dist[v] > dist[u] + w) { dist[v] = dist[u] + w; q.push({dist[v], v}); }
        }
    }
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int N, M; cin >> N >> M; long long cost = 0;
    for(int i = 1, u, v, l, c ; i <= M; i++){
        cin >> u >> v >> l >> c; cost += c; good[i] = true;
        edge.push_back({u, v, l, c, i});
        adj[u].push_back({v, l, i}); adj[v].push_back({u, l, i});
    }
    sort(edge.begin(), edge.end(), [](auto &x, auto &y){ return x[3] > y[3];});
    for (auto [u, v, l, c, i]: edge){
        good[i] = false; dijk(u, v);
        if(dist[v] > l) good[i] = true;
        else cost-=c;
    }
    cout << cost;
}