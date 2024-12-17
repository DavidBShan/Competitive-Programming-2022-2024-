#include <bits/stdc++.h>
using namespace std;
const long long MM = 2e4+5;
const long long IMM = 31;
vector<pair<long long, long long>> adj[MM]; long long dis[MM][IMM], m[IMM], cnt[IMM]; long long N, M, K; bool con[MM][IMM];
priority_queue<array<long long, 3>, vector<array<long long, 3>>, greater<array<long long, 3>>> q;
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> M >> K;
    for(long long i = 1; i <= K; i++) cin >> m[i];
    for(long long i = 1; i <= K; i++) cin >> cnt[i];
    for(long long i = 1; i <= K; i++){
        for(long long j = 0, x; j < cnt[i]; j++){
            cin >> x; con[x][i] = true;
        }
    }
    for(long long i = 1, u, v, w; i <= M; i++){
        cin >> u >> v >> w; adj[u].push_back({v, w}); adj[v].push_back({u, w});
    }
    memset(dis, 0x3f, sizeof(dis)); dis[1][0] = 0;
    q.push({0, 1, 0});
    while(!q.empty()){
        auto [d, u, k] = q.top(); q.pop();
        if(d > dis[u][k]) continue;
        if(k == K){
            cout << d << "\n"; return 0;
        }
        long long coef = con[u][k+1]? 0: 1;
        if(dis[u][k+1] > dis[u][k] + coef * m[k+1]){
            dis[u][k+1] = dis[u][k] + coef * m[k+1];
            q.push({dis[u][k+1], u, k+1});
        }
        for(auto [v, w]: adj[u]){
            if(dis[v][k] > dis[u][k] + w){
                dis[v][k] = dis[u][k] + w;
                q.push({dis[v][k], v, k});
            }
        }
    }
}