#include <bits/stdc++.h>
using namespace std;
const int MM = 3005;
int dp[MM][1<<10][2], a[MM], b[MM], N, M;

int fun(int i, int mask, bool can) {
    if(dp[i][mask][can] != -1) return dp[i][mask][can];
    int ans = 0;
    if(i <= N) {
        ans = max(ans, fun(i+1, mask, true)); 
        if(can) ans = max(ans, a[i] + fun(i+1, mask, false)); 
    } 
    for(int j = 0; j < M; j++) {
        if(mask & (1<<j)) continue;
        ans = max(ans, fun(i, mask | (1<<j), true));
        if(can) ans = max(ans, b[j] + fun(i, mask | (1<<j), false));
    }
    return dp[i][mask][can] = ans;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> a[i];
    }
    cin >> M;
    for(int j = 0; j < M; j++){
        cin >> b[j];
    }
    memset(dp, -1, sizeof(dp));
    cout << fun(0, 0, true) << "\n";
}