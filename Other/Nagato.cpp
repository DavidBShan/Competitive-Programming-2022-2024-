#include <bits/stdc++.h>
using namespace std;
const int MM = 5e5+3;
int n, d1[MM], d2[MM], ans[MM]; vector<int> adj[MM];

void dfs1(int u, int par){
    for(int v: adj[u]){
        if(v==par) continue;
        dfs1(v, u);
        if(d1[v] + 1 > d1[u]) {d2[u] = d1[u]; d1[u] = d1[v] + 1;}
        else if(d1[v] + 1 > d2[u]) d2[u] = d1[v] + 1; 
    }
}

void dfs2(int u, int par, int plen){
    ans[u] = max(d1[u], plen);
    for (int v: adj[u]) {
        if(v == par) continue;
        if(d1[v] + 1 == d1[u]) dfs2(v, u, max(plen, d2[u]) + 1);
        else dfs2(v, u, max(plen, d1[u]) + 1);
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 1, u, v; i < n; i++){
        cin >> u >> v; adj[u].push_back(v); adj[v].push_back(u);
    }
    dfs1(1, 0); dfs2(1, 0, 0);
    int mx = -1;
    for(int i = 1; i <= n; i++) mx = max(mx, ans[i]+1);
    cout << mx << " ";
    int count = 0;
    for(int i = 1; i <= n; i++) if(ans[i]+1 == mx) { count++; cout << i << " "; }
    cout << count-1 << "\n";
}