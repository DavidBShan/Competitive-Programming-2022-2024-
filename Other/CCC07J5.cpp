#include <bits/stdc++.h>
using namespace std;
const long long MM = 7e4+5;
long long dp[MM];
vector<long long> motel = {0, 990, 1010, 1970, 2030, 2940, 3060, 3930, 4060, 4970, 5030, 5990, 6010, 7000};
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    memset(dp, 0, sizeof(dp));
    long long A, B, N; cin >> A >> B >> N;
    for(long long i = 0; i < N; i++){
        long long x; cin >> x;
        motel.push_back(x);
    }
    sort(motel.begin(), motel.end());
    dp[0] = 1;
    for(long long i = 0; i < motel.size(); i++){
        for(long long j = 0; j < motel.size(); j++){
            if(abs(motel[j] - motel[i]) >= A && abs(motel[j] - motel[i]) <= B){
                dp[j] += dp[i];
            }
        }
    }
    cout << dp[motel.size()-1]  << endl;
}