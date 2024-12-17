#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    long long N, K; cin >> N >> K;
    if(K-N%K > N%K) cout << N%K << endl;
    else cout << K-N%K << endl;
}