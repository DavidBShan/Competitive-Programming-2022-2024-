#include <bits/stdc++.h>
using namespace std;
const int MM = 1e6+5;
int N, a[MM]; double dp[MM];
int main(){
    cin >> N;
    for(int i=1; i<=N; i++) {
        cin >> a[i];
    }
    fill(dp, dp+MM, 1000000000);
    dp[0] = 0;  dp[1] = a[1];
    for(int i=2; i<=N; i++) {
        dp[i] = dp[i-1] + a[i];
        if(i >= 2)  dp[i] = min(dp[i],  dp[i-2] + max(a[i-1], a[i]) + min(a[i-1], a[i])*0.75);
        if(i >= 3) dp[i] = min(dp[i],  dp[i-3] + a[i-2] + a[i-1] + a[i] - 0.5*min({a[i-2], a[i-1], a[i]}));
    }
    cout << fixed<<dp[N] << endl;
}