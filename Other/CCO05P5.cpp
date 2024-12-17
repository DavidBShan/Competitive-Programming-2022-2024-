#include <bits/stdc++.h>
using namespace std;
const int MM = 2e4+5;
int n, a[MM], b[MM], dp[MM][2];
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i] >> b[i];
    dp[1][0] = b[1] - 1 + b[1] - a[1]; dp[1][1] = b[1] - 1;
    for(int i = 2; i <= n; i++){
        dp[i][0] = min(abs(b[i] - a[i-1]) + dp[i-1][0], abs(b[i] - b[i-1]) + dp[i-1][1]) + b[i] - a[i];
        dp[i][1] = min(abs(a[i] - a[i-1]) + dp[i-1][0], abs(a[i] - b[i-1]) + dp[i-1][1]) + b[i] - a[i];
    }
    cout << min(dp[n][0] + n - a[n], dp[n][1] + n - b[n]) + (n-1) << "\n";
}