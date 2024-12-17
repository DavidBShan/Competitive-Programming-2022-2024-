#include <bits/stdc++.h>
using namespace std; vector<int> order;
void topSort(int inDeg[],vector<int> graph[]){
    queue<int> q; int v, w; 
    for(int i = 1; i < 8;i++){
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
    if(order.size()){
        cout << "Cannot complete these tasks. Going to bed.";
    }else{
        for(int i = 0; i < order.size();i++){
            cout << order[i] << " ";
        }
    }
}

int main(){
    vector<int> graph[8]; int inDeg[8];
    memset(inDeg,0,sizeof (inDeg));
    int inp1, inp2;
    cin >> inp1 >> inp2;
    while(inp1 !=0&& inp2 !=0){
        inDeg[inp2]++;
        graph[inp1].push_back(inp2);
    }
    topSort(inDeg, graph);
}