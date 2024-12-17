#include <bits/stdc++.h>
using namespace std;
bool visited[100001]; map<int,vector<int>> graph;
void DFS(int start){
    visited[start] = true;
    for(int i = 0; i < graph[start].size();i++){
        if(visited[graph[start][i]]==false){
            DFS(graph[start][i]);
        }
    }
}
int main(){
    int N,M, temp1,temp2;
    cin >> N >> M;
    for(int i = 0; i < M;i++){
        cin >> temp1 >> temp2;
        graph[temp2].push_back(temp1);
    }for(int i = 0; i < graph[1].size();i++){
        DFS(graph[1][i]);
    }
    for(int i = 1; i <= N;i++){
        if(visited[i]==true)cout << "1";
        else cout << "0";
    }
}