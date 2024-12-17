#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5+5;
int N, M;
vector<pair<int, int>> adj[MM];
pair<int, int> dis[MM]; bool vis[MM];
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> M;
    for(int i = 1, u ,v,  w; i <= M; i++){
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    priority_queue<pair<pair<int, int>, int>, vector<pair<pair<int, int>, int>>, greater<pair<pair<int, int>, int>>> q;
    memset(dis, 0x3f, sizeof(dis));
    dis[1] = {0, 0}; q.push({dis[1], 1});
    while(!q.empty()){
        pair<int, int> cur = q.top().first; int u = q.top().second; q.pop();
        if(vis[u]) continue;
        vis[u] = 1;
        for(auto e : adj[u]){
            int v = e.first, w = e.second;
            if(dis[v] > make_pair(cur.first + w, cur.second + 1)){
                dis[v] = {cur.first + w, cur.second + 1};
                q.push({dis[v], v});
            }
        }
    }
    if(dis[N].first == 0x3f3f3f3f) cout << -1 << "\n";
    else cout << dis[N].first << " " << dis[N].second << "\n";
}