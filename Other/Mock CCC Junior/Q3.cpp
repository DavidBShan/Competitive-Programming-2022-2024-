#include <bits/stdc++.h>
using namespace std;
map<long long, long long> gB; map<long long, long long> gR;

int main() {
    long long N; cin >> N; vector<long long> g; long long addedR = 0; long long latestG;
    for(long long i = 0; i < N; i++){
        char temp; cin >> temp;
        if(temp == 'G'){
            g.push_back(i);
            gR[i] = addedR;
            addedR = 0;
            latestG = i;
        }
        if(temp == 'R'){
            addedR++;
        }
        if(temp == 'B'){
            gB[latestG]++;
        }
    }
    long long ans = 0;
    for(long long i = 0; i < g.size(); i++){
        ans += gB[g[i]] * gR[g[i]];
    }
    cout << ans;
    return 0;
}