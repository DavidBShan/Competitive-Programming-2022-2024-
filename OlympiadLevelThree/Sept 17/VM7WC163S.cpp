#include <bits/stdc++.h>
using namespace std;
unordered_map<int, vector<int>> graph; vector<bool> visited;
int N, M, A, B, h1, h2;

void BFS(int ShaHou){
    queue<int> q;
    visited.resize(N, false);
    visited[ShaHou] = true;
    q.push(ShaHou);
    while (!q.empty()){
        ShaHou = q.front(); q.pop();
        for (int i = 0; i < graph[ShaHou].size(); i++){
            if (!visited[graph[ShaHou][i]]){
                visited[graph[ShaHou][i]] = true;
                q.push(graph[ShaHou][i]);
            }
        }
    }
}

int main(){
    cin >> N >> M>> A >> B; 
    for(int i = 0; i < M;i++){
        cin >> h1 >> h2;
        graph[h1-1].push_back(h2-1);
        graph[h2-1].push_back(h1-1);
    }
    BFS(A-1);
    if(visited[B-1]==true){
        cout << "GO SHAHIR!";
    }else{
        cout << "NO SHAHIR!";
    }
}