#include <bits/stdc++.h>
using namespace std;
const int MM = 4e5+5;
int N, M, Q, num; unordered_set<int> adj[MM];
void ins(int u, int v){
    if(adj[u].size() == 1) {
        if(adj[*adj[u].begin()].size() >= 2) num++;
    }
    if(adj[v].size() == 1) {
        if(adj[*adj[v].begin()].size() >= 2) num++;
    }
    adj[u].insert(v); adj[v].insert(u);
    num += (adj[u].size() >= 2 && adj[v].size() >= 2);
}
void rem(int u, int v) {
    num -= (adj[u].size() >= 2 && adj[v].size() >= 2);
    adj[u].erase(v); adj[v].erase(u);
    if(adj[u].size() == 1)  num -= adj[*adj[u].begin()].size() >= 2;
    if(adj[v].size() == 1)  num -= adj[*adj[v].begin()].size() >= 2;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M >> Q;
    for(int i=1, u, v; i<=M; i++) {
        cin >> u >> v; ins(u, v);
    }
    cout << (num > 0 ? "YES\n" : "NO\n");
    for(int i=1, u, v; i<=Q; i++) {
        cin >> u >> v;
        if(adj[u].count(v)) rem(u, v);
        else  ins(u, v);
        cout << (num > 0 ? "YES\n" : "NO\n");
    }
}