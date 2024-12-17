#include <bits/stdc++.h>
using namespace std;
const int MM = 1e4+5;
int N, T, dp[MM];
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> T;
    for(int i = 0, w1, w2, w3, v1, v2, v3; i < N; i++){
        cin >> w1 >> v1 >> w2 >> v2 >> w3 >> v3;
        for(int j = T; j >= 0; j--){
            if(j >= w1) dp[j] = max(dp[j], dp[j-w1]+v1);
            if(j >= w2) dp[j] = max(dp[j], dp[j-w2]+v2);
            if(j >= w3) dp[j] = max(dp[j], dp[j-w3]+v3);
        }
    }
    cout << dp[T] << endl;
}