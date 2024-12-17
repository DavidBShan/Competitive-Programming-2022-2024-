#include <bits/stdc++.h>
using namespace std;
const int MM = 25000005;
int N, M, Q; int difArr[MM];
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> M >> Q;
    memset(difArr, 0, sizeof(difArr));
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= M; j++){
            difArr[N*M - (N-i+1)*(M-j+1) + 2]--;
            difArr[i*j]++;
        }
    }
    int ansArr[MM]; memset(ansArr, 0, sizeof(ansArr));
    for (int i = 0; i <= MM; i++) {
        if (i == 0)
            ansArr[i] = difArr[i];
        else
            ansArr[i] = difArr[i] + ansArr[i - 1];
    }
    for(int i = 0; i < Q; i++){
        int x; cin >> x;
        cout << ansArr[x] << endl;
    }
}