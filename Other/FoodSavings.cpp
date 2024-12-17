#include <bits/stdc++.h>
using namespace std;
double prefSum[100001];
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N, C; cin >> N >> C;
    prefSum[0] = 0;
    for(int i = 1; i <= N; i++){
        double x; cin >> x;
        prefSum[i] = prefSum[i-1] + x;
    }
    for(int i = 0; i < C; i++){
        int l1, r1, l2, r2; cin >> l1 >> r1 >> l2 >> r2;
        double g1 = prefSum[r1] - prefSum[l1-1];
        double g2 = prefSum[r2] - prefSum[l2-1];
        double ogSum = g1 + g2;
        double newSum = min(((g1-10) > 0?(g1-10):0)+(g2/2.0), ((g2-10) > 0?(g2-10):0)+(g1/2.0));
        cout << fixed << setprecision(1) << abs(ogSum - newSum) << endl;
    }
}