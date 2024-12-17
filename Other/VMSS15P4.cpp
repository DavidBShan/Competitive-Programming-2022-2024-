#include <bits/stdc++.h>
using namespace std;
const int MFB = 2005, MM = 1e5+5;
int fb[MFB];
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T, N, M, G; cin >> T >> N >> M >> G;
    vector<pair<int, int>> adj[MM];
    for(int i = 0; i < G; i++) cin >> fb[i];
    for(int i = 0; i < M; i++){
        int a, b, c; cin >> a >> b >> c; adj[a].push_back({b, c});
    }
    int dist[MM];
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    memset(dist, 0x3f, sizeof(dist));  dist[0] = 0; pq.push({dist[0], 0});
    while(!pq.empty()){
        pair<int, int> cur = pq.top(); pq.pop();
        for(pair<int, int> e : adj[cur.second]){
            if(dist[e.first] > dist[cur.second] + e.second){
                dist[e.first] = dist[cur.second] + e.second;
                pq.push({dist[e.first], e.first});
            }
        }
    }
    int ans = 0;
    for(int i = 0; i < G; i++){
        //cout << dist[fb[i]] << "\n";
        if(dist[fb[i]] < T) ans++;
    }
    cout << ans;
}