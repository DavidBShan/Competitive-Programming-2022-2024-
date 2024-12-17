#include <bits/stdc++.h>
using namespace std;
int N, M;
map<int,vector<pair<int,int>>> graph;
const int MM = 10002;
int dis[MM]; int danger[MM]; 

void dijkstra(){
    
}

int main(){
    memset(dis,-1,sizeof dis);
    memset(danger,-1,sizeof dis);
    cin >> N >> M;
    for(int start, end, safe, i = 0; i < M;i++){
        cin >> start >> end >> safe;
        graph[start].push_back({end,safe});
        graph[end].push_back({start,safe});
    }
    dijkstra();
    cout << danger[MM] <<" "<<dis[MM];
}