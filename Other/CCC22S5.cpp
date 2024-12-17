#include <bits/stdc++.h>
using namespace std;
const int MM = 2e5+5;
int N, c[MM], dp[MM][2][2], tmp[2][2]; vector<int> adj[MM]; string s;
void dfs(int u, int p){
    dp[u][0][0] = 0; dp[u][0][1] = c[u];
    if(s[u-1] == 'Y') { dp[u][1][0] = 0;  dp[u][1][1] = c[u]; }
    for(int v : adj[u]){
        if(v == p) continue;
        dfs(v, u);
        memset(tmp, 0x3f, sizeof tmp);
        for(int i=0; i<=1; i++){
            for(int j=0; j<=1; j++){ 
                for(int k=0; k<=1; k++){
                    for(int l=0; l<=1; l++){ 
                        if(!k && !j) continue;
                        tmp[i|(k&l)][j] = min(tmp[i|(k&l)][j], dp[u][i][j] + dp[v][k][l]);
                    }
                }
            }
        }
        memcpy(dp[u], tmp, sizeof tmp);
    }
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N;  memset(dp, 0x3f, sizeof(dp));
    for(int i=1, u, v; i<N; i++) {
        cin >> u >> v; adj[u].push_back(v); adj[v].push_back(u);
    }
    cin >> s;
    for(int i=1; i<=N; i++) cin >> c[i];
    dfs(1, -1);
    cout << min(dp[1][1][0], dp[1][1][1]) << "\n";
}