#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N, K, h[100002], dp[100002];
    cin >> N >> K;
    for(int i = 1; i <= N; i++) cin >> h[i];
    fill(dp, dp+N+1, 1e9); dp[1] = 0;
    for(int i = 2; i <= N; i++){
        for(int j = i-1; j >= max(1, i-K); j--){
            dp[i] = min(dp[i], dp[j]+abs(h[i]-h[j]));
        }
    }
    cout << dp[N] << endl;
}