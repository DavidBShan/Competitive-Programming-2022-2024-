#include <bits/stdc++.h>
using namespace std;
int N, Q;map<int, vector<pair<int,int>>> graph;
int BFS(int startC, int distArr[]){
    queue<int> q; bool visited[N+1]; memset(visited,0,sizeof visited); int curNode;
    q.push(startC); visited[startC] = true; distArr[startC] = 0; int lastNode=0;
    while(!q.empty()){
        curNode = q.front(); q.pop(); if(distArr[curNode]>distArr[lastNode]) lastNode = curNode;
        for(pair<int,int>proc:graph[curNode]){
            if(!visited[proc.first]){
                distArr[proc.first]=distArr[curNode]+proc.second; visited[proc.first] = true; q.push(proc.first);
            }
        }
    }
    
    return lastNode;
}

int main(){
    cin >> N >> Q; int dist1[N+1]; int dist2[N+1]; int rand[N+1];int end1, end2;
    memset(dist1,-1,sizeof dist1); memset(dist2,-1,sizeof dist2); memset(rand,-1,sizeof rand); 
    for(int i = 1, c1,c2,w; i<N;i++){
        cin >> c1 >> c2 >> w;
        graph[c1].push_back({c2,w}); graph[c2].push_back({c1,w});
    }
    end1 = BFS(1,rand); end2 = BFS(end1,dist1); BFS(end2,dist2);
    for(int i = 0,cQ;i < Q;i++){
        cin >> cQ;
        cout << max(dist1[cQ],dist2[cQ])<<endl;
    }
}