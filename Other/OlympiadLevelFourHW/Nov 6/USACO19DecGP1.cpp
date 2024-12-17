#include <bits/stdc++.h>
using namespace std;
const int MM = 1003;
struct E{
    int v, w, f;
    bool operator < (const E & x) const{return w>x.w;}
};
int N, M, dis[MM][MM],ans; vector<E> adj[MM];
int main(){
    cin >> N >> M;
    for(int i = 1, u, v, w, f;i<=M;i++){
        cin >> u >> v >> w >> f;
        adj[u].push_back({v,w,f}); adj[v].push_back({u,w,f});
    }
    memset(dis, 0x3f, sizeof(dis));
    priority_queue<E> q;
    dis[1][1000] = 0;
    q.push({1,0,1000}); // why flow rate 1000?
    while(!q.empty()){
        auto [u,d,f] = q.top(); q.pop();
        if(d>dis[u][f]) continue;
        if (u == N) ans = max (ans, f*(int) 1e6/d);
        for(auto [v,w,k]: adj[u]){
            int f2 = min(f,k);
            if (dis[v][f2]>dis[u][f]+w){
                dis[v][f2] = dis[u][f]+w; q.push({v,dis[v][f2],f2});
            }
        }
    }
    cout << ans << endl;
}