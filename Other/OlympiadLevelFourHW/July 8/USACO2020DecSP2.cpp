#include <bits/stdc++.h>
using namespace std;
const int MM = 2503;
int N;
map<long long, long long> cx, cy;
int x[MM], y[MM], psa[MM][MM], id[MM];
long long ans = 0;

int query(int x1, int y1, int x2, int y2){
    return psa[x2][y2] - psa[x1-1][y2] - psa[x2][y1-1] + psa[x1-1][y1-1];
}

int main(){
    cin >> N;
    for(int i = 1; i <= N; i++){
        cin >> x[i] >> y[i];
        cx[x[i]] = cy[y[i]] = 0;
    }

    int count = 0; for(auto &e: cx) e.second = ++count;
    count = 0; for(auto &e: cy) e.second = ++count;

    for(int i = 1; i <= N; i++){
        x[i] = cx[x[i]]; y[i] = cy[y[i]]; id[x[i]] = i;
        psa[x[i]][y[i]] = 1;
    }

    for(int i = 1; i <= N; i++){
        for(int j = 1; j<= N; j++){
            psa[i][j] += psa[i-1][j] + psa[i][j-1] -psa[i-1][j-1];
        }
    }

    for(int i = 1; i <= N; i++){
        for(int j = i; j <= N; j++){
            int a = id[i]; int b = id[j];  
            int lft = min(y[a], y[b]); int rgt = max(y[a], y[b]);
            ans += 1LL*(query(i, 1, j, lft) * query(i, rgt, j, N));
        }
    }

    cout << ans + 1 << endl;
}