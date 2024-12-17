#include <bits/stdc++.h>
using namespace std;
int best, node;
int dfs(int v, bool* visited, map<int,vector<pair<int,int>>> graph, int c = 0){
    visited[v] = true;
    int ans = 0;
    for(int i = 0; i < graph[v].size(); i++){
        if(!visited[graph[v][i].first])ans = max(ans,dfs(graph[v][i].first, visited, graph, c+graph[v][i].second));
    }
    if(c > best){
        best = c; node = v ;
    }
    visited[v] = false;
    return max(c,ans);
}

int main(){
    int N; cin >> N; int distance[100001]; bool visited[100001];
    map<int,vector<pair<int,int>>> graph; int maxN = 0;
    int diameter = 0, start, end, time, cur;
    for(int i = 0; i < N;i++){
        cin >> start >> end >> time;
        diameter+=time; graph[start].push_back({end,time});     
        graph[end].push_back({start,time});
    }   
    maxN = dfs(0, visited, graph);
    cout << 2*diameter-maxN;
}