#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    long long L, N, rp, rb; cin >> L >> N >> rp >> rb;
    bool maxArr[L+1]; memset(maxArr, 0, sizeof(maxArr));
    long long curMax = -1; vector<pair<long long, long long>> inp;
    for(long long i = 0; i < N; i++){
        long long a, b; cin >> a >> b; inp.push_back({a, b});
    }
    sort(inp.begin(), inp.end());
    for(long long i = N-1; i >= 0; i--){
        long long a = inp[i].first, b = inp[i].second;
        if(b > curMax){
            maxArr[a] = 1; curMax = b;
        }
    }
    long long ans = 0; long long lastLoc = 0; long long tp = 0; long long tb = 0;
    for(long long i = 0; i < N; i++){
        if(maxArr[inp[i].first]){
            tp += (inp[i].first - lastLoc) * rp;
            tb += (inp[i].first - lastLoc) * rb;
            ans += (tb-tp)*(inp[i].second);
            tp = tb; lastLoc = inp[i].first;
        }
    }
    cout << -1*ans;
}