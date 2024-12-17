#include <bits/stdc++.h>
using namespace std;
int adjacency[1002][1002], vis[1002]; int N; bool flag = false;
void dfs(int u){
    vis[u] = 1; //visited, push to stack
    for(int v=1; v<=100; v++){
        if(!adjacency[u][v]) continue;
        if(vis[v] == 1) { flag = true; return; }
        if(vis[v] == 0) { dfs(v);}
    }
    vis[u] = 2; 
}
int main(){
    cin >> N; 
    for(int i = 1; i <= N;i++){
        for(int j = 1; j <= N;j++){
            cin >> adjacency[i][j];
        }
    }
    for(int i = 1; i <=N;i++){
        dfs(i);
    }
    if(flag == true) cout << "NO";
    else cout << "YES";
}