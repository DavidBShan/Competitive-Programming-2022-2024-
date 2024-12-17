#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;
vector<pair<int, int>> adj[MAXN];
int dist[MAXN];
bool vis[MAXN];
int n, m, k, l[MAXN], r[MAXN], w[MAXN], lo, hi;

bool check(int mid) {
    for (int i = 1; i <= n; i++) {
        dist[i] = 1e9;
        vis[i] = false;
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dist[1] = 0;
    pq.push({0, 1});
    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        if (vis[u]) continue;
        vis[u] = true;
        for (auto [v, w] : adj[u]) {
            int new_dist = dist[u] + (w > mid);
            if (new_dist < dist[v]) {
                dist[v] = new_dist;
                pq.push({dist[v], v});
            }
        }
    }
    return dist[n] <= k;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++) {
        cin >> l[i] >> r[i] >> w[i];
        adj[l[i]].push_back({r[i], w[i]});
        adj[r[i]].push_back({l[i], w[i]});
        lo = min(lo, w[i]);
        hi = max(hi, w[i]);
    }
    while (lo < hi) {
        int mid = (lo + hi) / 2;
        if (check(mid)) hi = mid;
        else lo = mid + 1;
    }
    if (check(lo)) cout << lo << '\n';
    else cout << -1 << '\n';
    return 0;
}