#include <bits/stdc++.h>
using namespace std;
const int MM = 655;
int N, maxV = 651; int psa[MM][MM];
int main(){
    int N; cin >> N;
    int x[N+1], y[N+1];
    for(int i = 1; i <= N; i++){
        cin >> x[i] >> y[i]; x[i]++; y[i]++; psa[x[i]][y[i]]++;
    }

    for(int i = 1; i <= maxV; i++){
        for(int j = 1; j <= maxV; j++){
            psa[i][j] += psa[i-1][j] + psa[i][j-1] - psa[i-1][j-1];
        }
    }

    for(int i = 1; i <= N; i++){
        int best = psa[maxV][maxV] - psa[x[i]][maxV] - psa[maxV][y[i]] + psa[x[i]][y[i]];
        int worst = psa[x[i]-1][y[i]-1];
        if(x[i]==maxV){
            worst+=psa[1][y[i]]-psa[1][y[i]-1];
        }if(y[i]==maxV){
            worst+=psa[x[i]][1]-psa[x[i]-1][1];
        }
        cout << best + 1 << " " << (N-worst) << "\n";
    }
}