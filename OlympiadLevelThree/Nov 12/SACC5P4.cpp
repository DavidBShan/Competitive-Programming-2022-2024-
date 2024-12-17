#include <bits/stdc++.h>
using namespace std;
int num, CInDeg, temp;  vector<int> order;

void topSort(int inDeg[],vector<int> graph[]){
    queue<int> q; int v, w; 
    for(int i = 1; i <= num;i++){
        if(inDeg[i]==0){
            q.push(i);
        }
    }
    while(!q.empty()){
        v = q.front(); q.pop(); order.push_back(v);
        for(int i = 0; i < graph[v].size();i++){
            if(--inDeg[graph[v][i]]==0){
                q.push(graph[v][i]);
            }
        }
    }
    for(int i = 0; i < order.size();i++){
        cout << order[i] << " ";
    }
}

int main(){
    cin >> num;
    int inDeg[num+1]; vector<int> graph[num+1];
    for(int i = 1; i <= num;i++){
        cin >> CInDeg;
        inDeg[i] = CInDeg;
        for(int j = 0; j < CInDeg;j++){
            cin >> temp;
            graph[temp].push_back(i);
        }
    }
    topSort(inDeg,graph);
}

