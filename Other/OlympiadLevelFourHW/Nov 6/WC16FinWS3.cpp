#include <bits/stdc++.h>
using namespace std;
const int MM = 402;
int N, K, a[MM], dp[MM][MM];

int main(){
    cin >> N >> K; K++;
    for(int i = 1; i <= N;i++){
        cin >> a[i];
    }
    memset(dp, 0x3f,sizeof(dp));
    dp[0][0] = 0;
    for(int i = 1; i <=N;i++){
        for(int j = i-1; j >=0;j--){
            int cost = 0, other = i - j - 1;
            for(int k = j+1;k<=i;k++){
                if(other > a[k]) cost += other -a[k];
            }for(int k = 1; k <=K;k++){
                dp[i][k] = min(dp[i][k], dp[j][k-1]+cost);
            }
        }
    }
    cout << dp[N][K]<<endl;
}