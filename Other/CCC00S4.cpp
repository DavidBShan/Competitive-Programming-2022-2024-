#include <bits/stdc++.h>
using namespace std;
const long long MM = 5281;
long long dp[MM];
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    long long T, N; cin >> T >> N;
    fill(dp, dp + MM, 1e9); dp[0] = 0;
    for(long long i = 0, temp; i < N; i++){
        cin >> temp;
        for(long long j = temp; j <= T; j++){
            dp[j] = min(dp[j], dp[j - temp] + 1);
        }
    }
    if(dp[T] == 1e9) cout << "Roberta acknowledges defeat." << '\n';
    else cout << "Roberta wins in " << dp[T] << " strokes." << '\n';
}