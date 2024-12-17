#include <bits/stdc++.h>
using namespace std;

int main(){
    int N; cin >> N; long long k; cin >> k;
     k--; int adj[N+1][N+1];int dis[N+1][N+1];
     for(int i = 1; i <=N;i++){
        for(int j = 1; j < N;j++){
            cin >> adj[i][j];
        }
     }
     int pre = 1, cur = 2; dis[pre][cur] = 1;
     while(true){
        int nxt = adj[cur][pre];
        if(dis[cur][nxt]>0) k%= dis[pre][cur] - dis[cur][nxt]+1;
        if(k==0){
            cout << pre; return;
        }
        dis[cur][nxt] = dis[pre][cur]+1;
        k--; pre = cur; cur = nxt;
     }

}