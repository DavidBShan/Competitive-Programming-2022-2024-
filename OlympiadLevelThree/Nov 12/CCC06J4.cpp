#include <bits/stdc++.h>
using namespace std; vector<int> order;
void topSort(int inDeg[],vector<int> graph[]){
    priority_queue<int, vector<int>, std::greater<int> > q; int v, w; 
    for(int i = 1; i < 8;i++){
        if(inDeg[i]==0){
            q.push(i);
        }
    }
    while(!q.empty()){
        v = q.top(); q.pop(); order.push_back(v);
        for(int i = 0; i < graph[v].size();i++){
            if(--inDeg[graph[v][i]]==0){
                q.push(graph[v][i]);

            }
        }
    }
    if(order.size()!=7){
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
    inDeg[7]++; inDeg[4]+=2;inDeg[1]++; inDeg[5];
    graph[1].push_back(7); graph[1].push_back(4); graph[2].push_back(1); graph[3].push_back(4); graph[3].push_back(5);
    int inp1, inp2;
    cin >> inp1 >> inp2;
    while(inp1 !=0&& inp2 !=0){
        inDeg[inp2]++;
        graph[inp1].push_back(inp2);
        cin >> inp1 >> inp2;
    }
    topSort(inDeg, graph);
}