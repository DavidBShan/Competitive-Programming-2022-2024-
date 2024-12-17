#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5+5;
double dp[MM], arr[MM];
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    double N; cin >> N;
    fill(dp, dp + MM, 1e18);
    for(int i = 1; i <= N; i++){ cin >> arr[i];}
    dp[0] = 0; dp[1] = arr[1];
    for(int i = 2; i <= N; i++){
        dp[i] = dp[i-1] + arr[i];
        if(i >= 2){
            dp[i] = min(dp[i], dp[i-2] + arr[i] + arr[i-1] - 0.5 * min(arr[i], arr[i-1]));
        }if(i >= 3){
            dp[i] = min(dp[i], dp[i-3] + arr[i] + arr[i-1] + arr[i-2] - min(arr[i], min(arr[i-1], arr[i-2])));
        }
    }
    cout << fixed << setprecision(1) << dp[(int)N] << '\n';
}