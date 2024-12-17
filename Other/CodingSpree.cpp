#include <bits/stdc++.h>
using namespace std;
const int MM = 1e4+5;
int N, T, dp[MM];
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> T; memset(dp, 0, sizeof(dp));
    for(int i = 0, a, b; i < N; i++){
        cin >> a >> b;
        for(int j = T; j >= b; j--){
            dp[j] = max(dp[j], dp[j-b]+a);
        }
    }
    cout << dp[T];
}