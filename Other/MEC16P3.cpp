#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> vec;
const int MM = 105;
int N, T, dp[MM];
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> T;
    for(int i = 0, n, a, b; i < N; i++){
        vec.clear();
        cin >> n; int w = 0, t = 0;
        for(int j = 0; j < n; j++){
            cin >> a >> b;
            w += a; t += b;
            vec.push_back({w, t});
        }
        for(int j = T; j >= 0; j--){
            for(auto k : vec){
                if(j >= k.first){
                    dp[j] = max(dp[j], dp[j-k.first]+k.second);
                }
            }
        }
    }
    cout << dp[T] << '\n';
}