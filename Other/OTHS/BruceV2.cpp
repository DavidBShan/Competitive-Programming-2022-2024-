#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5+2;
int N, p[MM], leaf[MM], val[MM], num; vector<int> adj[MM];

int dfs(int u, int pa){
    int potion = val[u];
    for(int v : adj[u]){
        if(v == pa) continue;
        potion += dfs(v, u);
        leaf[u] += leaf[v];
    }
    return min(potion, leaf[u]);
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N;
    for(int i = 1; i <= N; i++){
        cin >> p[i];
    }
    for(int i = 1, u, v; i < N; i++){
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i = 2; i<= N; i++){
        if(adj[i].size() == 1){
            num++; leaf[i]++;
        }
    }
    for(int i = 1; i <= num; i++) val[p[i]]++;
    cout << dfs(1, 0) << endl;
}