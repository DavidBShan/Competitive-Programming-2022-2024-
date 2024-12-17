#include <bits/stdc++.h>
using namespace std;
int num, numCon, temp1, temp2;
void topSort(int inDeg[],vector<int> graph[]){
    queue<int> q; int v, w, counter = 0; 
    for(int i = 1; i <= num;i++){
        if(inDeg[i]==0){
            q.push(i);
        }
    }
    while(!q.empty()){
        v = q.front(); q.pop(); counter++;
        for(int i = 0; i < graph[v].size();i++){
            if(--inDeg[graph[v][i]]==0){
                q.push(graph[v][i]);
            }
        }
        /*
        if(counter>100000){
            break;
        }*/
    }
    if(counter != num) cout << "N";
    else cout << "Y";
}
int main(){
    cin >> num; cin >> numCon;
    int InDeg[num+1]; memset(InDeg,0,sizeof InDeg); vector<int> graph[num+1];
    for(int i = 0; i < numCon;i++){
        cin >> temp1 >> temp2;
        InDeg[temp2]++; graph[temp1].push_back(temp2);
    }
    topSort(InDeg,graph);
}