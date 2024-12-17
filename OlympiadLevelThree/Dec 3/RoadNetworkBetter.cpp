#include<bits/stdc++.h>
using namespace std;
const int MM = 1003;
int main(){
    int N, M, x[MM], y[MM]; vector<pair<double,int>> locDis[MM]; double dis[MM]; bool vis[MM];
    cin >> N >> M;
    for(int i = 1; i <= N;i++){
        cin >> x[i] >> y[i];
        for(int j = 1;j<i;j++){
            locDis[i].push_back({hypot(x[i]-x[j], y[i]-y[j]), j});
            locDis[j].push_back({hypot(x[i]-x[j], y[i]-y[j]), i});
        }
    }
    for(int i = 0,x,y; i < M;i++){
        cin >> x >> y;
        locDis[x].push_back({0,y}); locDis[y].push_back({0,x});
    }
    priority_queue<pair<double,int>, vector<pair<double,int>>, greater<pair<double,int>>> q;
    fill(dis,dis+MM,1e18);
    dis[1] = 0; q.push({0,1});
    while(!q.empty()){
        double d = q.top().first; int u = q.top().second; q.pop();
        if(vis[u]) continue;
        vis[u] = true;
        for(auto e : locDis[u]){
            double w = e.first; int v = e.second;
            if(!vis[v] && dis[v] > w) { dis[v] = w; q.push({dis[v], v}); }
        }
    }
    double ans = 0;
    for(int i=1; i<=N; i++) ans += dis[i];
    cout << fixed << setprecision(2) << ans << endl;

}