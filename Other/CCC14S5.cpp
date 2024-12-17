#include <bits/stdc++.h>
using namespace std;
const int MM = 2002;
int n, x[MM], y[MM], dp[MM], dist[MM], temp[MM]; map<int, int> memo[MM];
vector<array<int, 3>> vec;
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> x[i] >> y[i];
    for(int i = 0; i <= n; i++){
        for(int j = i+1; j <= n; j++){
            int dis = (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]);
            vec.push_back({dis, i, j});
        }
    }
    sort(vec.begin(), vec.end());
    for(int i = 0; i < vec.size(); i++){
        int u = vec[i][1], v = vec[i][2], d = vec[i][0];
        if(d != dist[u]) {
            temp[u] = dp[u]; dist[u] = d; 
        }if(d != dist[v]){
            temp[v] = dp[v]; dist[v] = d;
        }if(u==0) dp[u] = max(dp[u], temp[v] + 1);
        else{
            dp[u] = max(dp[u], temp[v] + 1);
            dp[v] = max(dp[v], temp[u] + 1);
        }
    }
    cout << dp[0];
}