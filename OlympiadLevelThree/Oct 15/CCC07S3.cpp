#include <bits/stdc++.h>
using namespace std;
int N; map<int, int>adj;int vis[10002], dist;
int main(){ 
    cin >> N; int u, v;
    for(int i = 0; i < N;i++){
        cin >> u >> v; adj[u] = v;
    }
    while(true){
        cin >> u >> v;
        dist = -1;
        if(u == 0) break;
        memset(vis, 0, sizeof(vis));
        while(u!=v && vis[u]==0){
            dist++; vis[u]=1; u = adj[u];
        }
        if(u == v) {cout << "Yes ";cout << dist<<endl;}
        else cout <<"No"<<endl;
    }
}