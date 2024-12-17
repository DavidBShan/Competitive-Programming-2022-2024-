#include <bits/stdc++.h>
using namespace std;
const int MM = 1e4+5;
int N, M, x[MM], y[MM]; vector<pair<double, int>> adj[MM]; bool vis[MM]; double dist[MM];
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> M;
    for(int i = 1; i <= N; i++) {
        cin >> x[i] >> y[i];
        for(int j = 1; j < i; j++){
            double d = sqrt(pow(x[i]-x[j], 2) + pow(y[i]-y[j], 2));
            adj[i].push_back({d, j});
            adj[j].push_back({d, i});
        }
    }
    for(int i = 1, a, b; i <= M; i++){
        cin >> a >> b;
        adj[a].push_back({0, b});
        adj[b].push_back({0, a});
    }
    priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> pq;
    fill(dist, dist+MM, 1e9);
    pq.push({0, 1}); dist[1] = 0; 
    while(!pq.empty()){
        int cur = pq.top().second; pq.pop();
        if(vis[cur]) continue; vis[cur] = 1;
        for(auto e : adj[cur]){
            int v = e.second; double w = e.first;
            if(!vis[v] && dist[v] > w){
                dist[v] = w;
                pq.push({dist[v], v});
            }
        }
    }
    double ans = 0;
    for(int i = 1; i <= N; i++) ans += dist[i];
    cout << fixed << setprecision(2) << ans;
}