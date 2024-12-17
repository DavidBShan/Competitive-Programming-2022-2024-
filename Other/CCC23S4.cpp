#include <bits/stdc++.h>
using namespace std;

#define ar array
#define ll long long

const int MAX_N = 1e5 + 1;
const int MOD = 1e9 + 7;
const int INF = 1e9;
const ll LINF = 1e15;

int n, m;
vector<ar<int,3>> adj[MAX_N];
vector<ll> dist;

void dijkstra(int s) {
    dist.assign(n + 1, LINF);
    priority_queue<ar<ll,2>, vector<ar<ll,2>>, greater<ar<ll,2>>> pq;
    dist[s] = 0; pq.push({0, s});
    while (pq.size()) {
        auto [d, u] = pq.top(); pq.pop();
        if (d > dist[u]) continue;
        for (auto [v, w, c] : adj[u]) {
            if (dist[v] > dist[u] + c) {
                dist[v] = dist[u] + c;
                pq.push({dist[v], v});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v, w, c; cin >> u >> v >> w >> c;
        adj[u].push_back({v, w, c});
        adj[v].push_back({u, w, c});
    }
    dijkstra(1); int sum = 0;
    for (int i = 1; i <= n; i++) sum+=dist[i];
    cout << sum<<"\n";
}