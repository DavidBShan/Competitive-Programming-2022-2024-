#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
const int MM = 2e5+5;
int N, M, in[MM]; vector<int> adj[MM], ans; queue<int> q;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    for(int i=1, u, v; i<=M; i++){
        cin >> u >> v; adj[v].push_back(u); in[u]++;
    }
    for(int i=1; i<=N; i++) {
        if(!in[i]) q.push(i);
    }
    while(!q.empty()) {
        int u = q.front(); q.pop(); ans.push_back(u);
        for(int v : adj[u]){
            if(--in[v] == 0) q.push(v);
        }
    }
    if(ans.size() != N) cout << -1 << "\n";
    else {
        cout << N << "\n";
        for(int x : ans) cout << x << " 1\n";
    }
}