#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int N; cin >> N; double V[N]; double minV = 1e9+7;
    for(int i = 0; i < N; i++){
        cin >> V[i];
    }
    sort(V, V+N);
    for(int i = 1; i < N-1; i++){
        minV = min(minV, (V[i+1]-V[i-1])/2);
    }
    cout << setprecision(1) << fixed << minV;
}