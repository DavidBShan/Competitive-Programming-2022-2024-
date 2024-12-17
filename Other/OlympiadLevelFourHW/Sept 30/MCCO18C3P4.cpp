#include <bits/stdc++.h>
using namespace std;
const int MM = 5e4+4, logMM = 18;
int N, Q; int maxST[logMM][MM], minST[logMM][MM];
int maxQuery(int L, int R){
    int k = log2(R-L+1);
    return max(maxST[k][L], maxST[k][R-(1<<k)+1]);
}
int minQuery(int L, int R){
    int k = log2(R-L+1);
    return min(minST[k][L], minST[k][R-(1<<k)+1]);
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> Q;
    for(int i = 1; i <= N; i++) {cin >> maxST[0][i]; minST[0][i] = maxST[0][i];}
    for(int i = 1; i <= log2(N); i++){
        for(int j = 1; j+(1<<i)-1<=N; j++){
            maxST[i][j] = max(maxST[i-1][j], maxST[i-1][j+(1<<(i-1))]);
            minST[i][j] = min(minST[i-1][j], minST[i-1][j+(1<<(i-1))]);
        }
    }
    for(int i = 0; i < Q; i++){
        int L, R; cin >> L >> R;
        cout << maxQuery(L, R) - minQuery(L, R) << "\n";
    }
}