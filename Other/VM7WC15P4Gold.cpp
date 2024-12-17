#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m; priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<pair<int, int>> adj[n+1];
    for(int i = 0; i < m; i++){
        int a, b, time; cin >> a >> b >> time;
        adj[a].push_back({b, time}); adj[b].push_back({a, time});
    }
    int distAca[n+1], distDC[n+1]; fill(distAca, distAca+n+1, 1e9); distAca[0] = 0; pq.push({0, 0});
    while(!pq.empty()){
        int u = pq.top().second; pq.pop();
        for(auto v : adj[u]){
            if(distAca[v.first] > distAca[u] + v.second){
                distAca[v.first] = distAca[u] + v.second;
                pq.push({distAca[v.first], v.first});
            }
        }
    }
    pq = priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>();
    fill(distDC, distDC+n+1, 1e9); distDC[n-1] = 0; pq.push({n-1, n-1});
    while(!pq.empty()){
        int u = pq.top().second; pq.pop();
        for(auto v : adj[u]){
            if(distDC[v.first] > distDC[u] + v.second){
                distDC[v.first] = distDC[u] + v.second;
                pq.push({distDC[v.first], v.first});
            }
        }
    }
    int max = 0;
    for(int i = 0; i < n; i++){
        if(distAca[i] + distDC[i] > max) max = distAca[i] + distDC[i];
    }
    cout << max;
}