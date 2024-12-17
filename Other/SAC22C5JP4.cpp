#include <bits/stdc++.h>
using namespace std;
const int MM = 2e5+5;
int N, inDeg[MM]; vector<int> adj[MM]; vector<int> ans;

void topoSort(){
    queue<int> q;
    for(int i = 1; i <= N; i++) if(inDeg[i] == 0) q.push(i);
    while(!q.empty()){
        int cur = q.front(); q.pop(); ans.push_back(cur);
        for(int v : adj[cur]){
            inDeg[v]--;
            if(inDeg[v] == 0) q.push(v);
        }
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N; memset(inDeg, 0, sizeof inDeg);
    for(int i = 1, a; i <= N; i++){
        cin >> a; inDeg[i] = a;
        for(int j = 0, b; j < a; j++){
            cin >> b; adj[b].push_back(i);
        }
    }
    topoSort();
    for(int i : ans) cout << i << " ";
}