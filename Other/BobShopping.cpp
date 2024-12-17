#include <bits/stdc++.h>
using namespace std;
const long long MM = 1005;
long long dp[MM], arr[MM], val[MM];
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    long long N, M, W; cin >> N >> M >> W;
    for(long long i = 1, p, s; i <= N; i++){
        cin >> p >> s; arr[i] = p; val[i] = s;
        for(long long j = p; j <=W; j++){
            dp[j] = max(dp[j], dp[j-p]+s);
        }
    }
    for(long long i = 1, q, t, d, a; i <= M; i++){
        cin >> q >> t >> d >> a;
        int last = d;
        for(long long k = 1; k <= a; k*=2){
            long long w = d*k, v = val[t]*k*q;
            int temp = 0;
            for(long long j = W; j >= w; j--){
                if(dp[j-w] && temp < k){
                    temp = j;
                    dp[j] = max(dp[j], dp[j-w]+v);
                }
            }
        }
    }
    cout << dp[W] << "\n";
}