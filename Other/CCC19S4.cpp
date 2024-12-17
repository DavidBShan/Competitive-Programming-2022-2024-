#include <bits/stdc++.h>
using namespace std;
const int MM = 1e6+5;
long long n, k, attr[MM], day[MM], PMX[MM];
long long dp[MM], dp1[MM], dp2[MM];
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        cin >> attr[i];
        day[i] = (i+k-1)/k;
    }
    for(int i = 1; i <= n; i++){
        dp[i] = PMX[i] = max(PMX[i-1], attr[i]);
    }
    for(int i = k+1; i <= n; i+=k){
        long long smx = 0;
        for (int j = (day[i]-1)*k; j > (day[i]-2)*k; j--) {
            dp1[j] = max(dp1[j+1], dp[j]);
            dp2[j] = max(dp2[j+1], dp[j]+smx);
            smx = max(smx, attr[j]);
        }
        for (int j = i; j <= min(i+k, n); j++) {
            if(day[j] == day[j-1]) PMX[j] = max(PMX[j-1], attr[j]);
            else PMX[j] = attr[j];
            dp[j] = max(dp1[j-k] + PMX[j],  dp2[j-k]);
        }
    }
    cout << dp[n];
}