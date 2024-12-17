#include <bits/stdc++.h>
using namespace std;
const int MM=30;
typedef pair<int, int> pi;
int K, a[MM], dp[MM], flag, s, e; vector<pi> g;
int main(){
    cin >> K; g.push_back({0, 0});
    for(int i=1; i<=K; i++){
        cin >> a[i];
        if(!flag && a[i]){ s = i; flag = 1;}
        if(flag && !a[i]) {
            e = i-1; flag = 0;
            g.push_back({s, e});
        }
    }
    //for(int i = 0; i < g.size(); i++) cout << g[i].first << " " << g[i].second << endl;
    if(flag) g.push_back({s, K});
    memset(dp, 0x3f, sizeof(dp)); dp[0] = 0;
    for(int i=1; i<g.size(); i++){
        int on = 0;
        for(int j=i; j>0; j--){
            int len = g[i].second - g[j].first + 1; s = g[j].first;
            if(len >= 8) break;
            on += g[j].second - g[j].first + 1;
            if(len < 4) len = 4;
            if((len==6 && a[s+2] && a[s+3]) || (len==7 && a[s+3])) continue;
            dp[i] = min(dp[i], dp[j-1] + len - on);
        }
    }
    cout << dp[(int)g.size() - 1] << endl;
}