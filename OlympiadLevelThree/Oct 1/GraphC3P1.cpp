#include<bits/stdc++.h>
using namespace std;
 
int main(){
    int N, M, cityA, cityB, K, office, temp, maxDis = -1;
    map<int, vector<int>> graph; int distance[30001]; memset(distance, -1, sizeof distance); queue<int> q;
    cin >> N >> M;
    for(int i = 0; i < M; i++){
        cin >> cityA >> cityB;
        graph[cityA].push_back(cityB); graph[cityB].push_back(cityA);
    }cin >> K;
    for(int i = 0; i < K;i++){
        cin >> office;
        q.push(office); distance[office] = 0;
    }while(!q.empty()){
        temp = q.front(); q.pop();
        for(int i = 0; i < graph[temp].size();i++){
            if(distance[graph[temp][i]]==-1){
                distance[graph[temp][i]] = distance[temp]+1;
                q.push(graph[temp][i]);
            }
        }
    }for(int i = 1; i <= N;i++){
        maxDis = max(maxDis, distance[i]);
    }
    cout << maxDis;
}