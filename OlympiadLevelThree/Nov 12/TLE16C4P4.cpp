#include <bits/stdc++.h>
using namespace std;
int N, M, Q,u,v,l;
map<int,vector<pair<int,int>>> graph; bool visited[100001];int dis[100001]; int maxC = -1; int minC = 0x3f;
void bfs1(int start){
    int v, d;
    memset(visited,0,sizeof visited);
    queue<pair<int,int>>q; q.push({start,0}); visited[start] = true;dis[start] = 0;
    while(!q.empty()){
        v = q.front().first; d = q.front().second; q.pop();
        for(int i = 0; i < graph[v].size();i++){
            if(!visited[graph[v][i].first]){
                visited[graph[v][i].first] = true;
                dis[graph[v][i].first] = dis[v]+d;
                maxC = max(maxC,dis[graph[v][i].first]);
                q.push({graph[v][i].first,graph[v][i].second});
            }
        }
    }
}
void bfs2(int start){
    int v, d;
    memset(visited,0,sizeof visited);
    queue<pair<int,int>>q; q.push({start,0}); visited[start] = true;dis[start] = 0;
    while(!q.empty()){
        v = q.front().first; d = q.front().second; q.pop();
        for(int i = 0; i < graph[v].size();i++){
            if(!visited[graph[v][i].first]){
                visited[graph[v][i].first] = true;
                dis[graph[v][i].first] = dis[v]+d;
                minC = min(minC,dis[graph[v][i].first]);
                q.push({graph[v][i].first,graph[v][i].second});
            }
        }
    }
}
int main(){
    cin >> N >> M >> Q;
    for(int i = 0; i < M;i++){
        cin >> u >> v >> l;
        graph[u].push_back({v,l});graph[v].push_back({u,l});
    }
}