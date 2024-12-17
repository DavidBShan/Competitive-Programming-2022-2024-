#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N; cin >> N;
    double dp[N + 1]; int flav[N + 1]; int last[N+1];
    memset(last, 0, sizeof(last));
    for (int i = 1; i <= N; i++) cin >> flav[i];
    dp[N] = flav[N] == flav[1] ? 1 : 0;
    double sufSum = dp[N]; last[flav[N]] = N;
    for (int i = N-1; i >= 1; i--) {
        if(flav[i] == flav[1]) dp[i] = 1;
        else if(last[flav[i]] != 0) dp[i] = dp[last[flav[i]]];
        else{
            dp[i] = (1 + sufSum) / (N-i+1);
        }
        sufSum+=dp[i]; last[flav[i]] = i;
    }
    //cout << fixed << setprecision(9) << dp[N-2] << "\n";
    cout << fixed << setprecision(9) << sufSum / N << "\n";
    return 0;
}
