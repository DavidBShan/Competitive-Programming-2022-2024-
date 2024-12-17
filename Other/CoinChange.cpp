#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int x, n; cin >> x >> n; int dp[x+1]; 
    fill(dp, dp + x+1, 1e9);
    dp[0] = 0;
    for(int i = 0, temp; i < n; i++){
        cin >> temp;
        for(int j = temp; j <= x; j++){
            dp[j] = min(dp[j], dp[j-temp]+1);
        }
    }
    cout << (dp[x] == 1e9 ? -1 : dp[x]) << '\n';
}