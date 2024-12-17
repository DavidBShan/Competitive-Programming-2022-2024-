#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5+1;
bool pho[MM]; vector<int> adj[MM]; int far, cnt = 0, farNode;
void dfs1(int node, int parent){
    for(int i = 0; i < adj[node].size(); i++){
        if(adj[node][i] != parent){
            dfs1(adj[node][i], node); pho[node] |= pho[adj[node][i]];
        }
    }
    cnt += pho[node];
}

void dfs2(int node, int parent, int dis){
    if(dis > far){far = dis; farNode = node;}
    for(int i = 0; i < adj[node].size(); i++){
        if(adj[node][i] != parent && pho[adj[node][i]]){
            dfs2(adj[node][i], node, dis+1);
        }
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int N, M; cin >> N >> M; 
    int rit;
    for(int i = 0, temp; i < M; i++){
        cin >> temp; pho[temp] = true; rit = temp;
    }
    for(int i = 0, a, b; i < N-1; i++){
        cin >> a >> b; adj[a].push_back(b); adj[b].push_back(a);
    }
    dfs1(rit, -1);
    dfs2(rit, -1, 0);
    dfs2(farNode, -1, 0);
    cout << 2*(cnt-1) - far << endl;
}