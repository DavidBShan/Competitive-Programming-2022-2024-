#include <bits/stdc++.h>
using namespace std;
const int mod = 3;

int main(){
    int ABC[3][3], dp[3][3], ans = 0; memset(dp, -1,sizeof dp);
    for(int i = 0; i < 3;i++){
        for(int j = 0; j < 3;j++){
            cin >> ABC[i][j];
        }
    }

    for(int i = 0; i < 3;i++){
        for(int j = i; j < 3;j++){
            if(i==j) dp[i][j] = 0;
            else dp[i][j] = dp[i][j-1];
            if(ABC[1][j%mod]==ABC[0][(j+2)%mod]){
                dp[i][j]+=ABC[2][j];
            }
            ans = max(ans,dp[i][j]);
        }
    }
    cout << ans;
}