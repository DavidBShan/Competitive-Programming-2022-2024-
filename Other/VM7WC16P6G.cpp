#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5+5;
int N, M; vector<int> adj[MM]; int ord[MM], low[MM], idx = 0; set<int> ans;

void tarjan(int cur, int pre){
    int cnt = 0; ord[cur] = low[cur] = ++idx;
    for(int v : adj[cur]){
        if(v == pre) continue;
        if(!ord[v]){
            tarjan(v, cur); cnt++;
            low[cur] = min(low[cur], low[v]);
            if(pre != -1 && low[v] >= ord[cur]) ans.insert(cur);
        }else low[cur] = min(low[cur], ord[v]);
    }
    if(pre == -1 && cnt > 1) ans.insert(cur);
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> M;
    for(int i = 1, u, v; i <= M; i++){
        cin >> u >> v; adj[u].push_back(v); adj[v].push_back(u);
    }
    for(int i = 1; i <= N; i++){
        if(!ord[i]) tarjan(i, -1);
    }
    cout << ans.size() << "\n";
    for(int x : ans) cout << x << "\n";
}