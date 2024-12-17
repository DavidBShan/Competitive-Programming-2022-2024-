#include <bits/stdc++.h>
using namespace std;
const int MM = 2e5+5;
int N, arr[MM], ans = 0, prefixGCD[MM], suffixGCD[MM];
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> arr[i];
    }
    prefixGCD[0] = arr[0]; suffixGCD[N-1] = arr[N-1];
    for(int i = 1; i < N; i++){
        prefixGCD[i] = __gcd(prefixGCD[i-1], arr[i]);
    }
    for(int i = N-2; i >= 0; i--){
        suffixGCD[i] = __gcd(suffixGCD[i+1], arr[i]);
    }
    for(int i = 0; i < N; i++){
        ans = max(ans, __gcd(prefixGCD[i-1], suffixGCD[i+1]));
    }
    cout << ans;
}