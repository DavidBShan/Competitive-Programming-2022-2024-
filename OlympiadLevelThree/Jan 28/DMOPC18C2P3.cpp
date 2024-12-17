#include <bits/stdc++.h>
using namespace std;
const int MM = 100002;
map<int,vector<int>> roads;
int buildN; int roadN; int storeN; int startB; int endB;
long long startDis[MM]; long long endDis[MM];
bool vis[MM];
vector<int> store; 

void dijsktra (int start, long long dis[]){
    fill(vis, vis+MM, 0);
    priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long ,int>>> q;
    dis[start]=0; q.push({dis[start], start});
    while(!q.empty()){
        int node = q.top().second;  int distanceNode = q.top().first; q.pop();
        if(vis[node]==true) continue;
        vis[node] = true;
        for(int i = 0; i < roads[node].size();i++){
             int u = roads[node][i];
             if(dis[u]>distanceNode+1){
                dis[u] = dis[node]+1; q.push({dis[u],u});
             }
        }
    }
}

int main(){
    long long minL = 1e18;
    cin >> buildN >> roadN >> storeN >> startB >> endB;
    for(int storeB, i = 0; i < storeN;i++){
        cin >> storeB;
        store.push_back(storeB);
    }
    for(int first, second, i = 0; i < roadN;i++){
        cin >> first >> second;
        roads[first].push_back(second); roads[second].push_back(first);
    }  
    fill(startDis,startDis+MM,1e18); fill(endDis,endDis+MM,1e18);
    dijsktra(startB,startDis); dijsktra(endB, endDis);
    for(int i = 0; i < storeN;i++){
        if((startDis[store[i]]+endDis[store[i]])<minL){
            minL = startDis[store[i]]+endDis[store[i]];
        }
    }
    cout << minL;
}