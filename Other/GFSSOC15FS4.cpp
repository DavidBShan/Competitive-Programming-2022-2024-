#include <bits/stdc++.h>
using namespace std;
const int MM = 5e5+5;
int n, m; long long dis1[MM], dis2[MM]; vector<pair<int, int>> adj[MM], revAdj[MM]; bool vis[MM];

void dijk(int st, vector<pair<int, int>> adj[], long long dis[]){
    fill(dis, dis+MM, 1e18);  fill(vis, vis+MM, 0);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
    dis[st] = 0; q.push({dis[st], st});
    while(!q.empty()){
        int u = q.top().second; q.pop();
        if(vis[u]) continue;
        vis[u] = true;
        for(auto [w, v] : adj[u]){
            if(dis[v] > dis[u] + w) {
                dis[v] = dis[u] + w; q.push({dis[v], v});
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 0, a, b, c; i < m; i++){
        cin >> a >> b >> c;
        adj[a].push_back({c, b});
        revAdj[b].push_back({c, a});
    }
    dijk(1, adj, dis1); dijk(n, revAdj, dis2);
    int d; cin >> d;
    long long ans = dis1[n];
    for (int i = 0, a, b, c; i < d; i++){
        cin >> a >> b >> c;
        if (dis1[a]+dis2[b]+c < ans) ans = dis1[a]+dis2[b]+c;
    }
    if(ans > 1e12){
        cout << -1; return 0;
    }
    cout << ans;
}