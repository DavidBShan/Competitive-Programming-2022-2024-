#include <bits/stdc++.h>
using namespace std;
const int MM = 702;
int dp[MM], arr[MM], sum = 0;
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N; cin >> N;
    memset(dp, 0, sizeof(dp)); memset(arr, 0, sizeof(arr));
    for(int i = 1; i <= N; i++){
        cin >> arr[i]; sum += arr[i];
    }
    dp[0] = 1; int temp = sum/2;
    for(int i = 1; i <= N; i++){
        for(int j = temp; j >= arr[i]; j--){
            if(j - arr[i] >= 0 && !dp[j]) dp[j] = dp[j-arr[i]];
        }
    }
    for(int i = temp; i >= 0; i--){
        if(dp[i]) {cout << sum-2*i << "\n"; return 0;}
    }
}