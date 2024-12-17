#include <bits/stdc++.h>
using namespace std;
const int LOG = 50;
int N; long long T; string s;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> T >> s; vector<int> a(N), b(N);
    for(int i = 0; i < N; i++){
        a[i] = s[i] - '0';
    }
    for(int k = LOG; k>=0; k--){
        if(T >> k & 1){
            long long d = 1LL << k;
            for(int i = 0; i < N; i++){
                b[i] = a[(i + d) % N] ^ a[(i - d) % N + N];
            }
            swap(a, b);
        }
    }
    for(int i = 0; i < N; i++) cout << a[i];
    cout << endl;
}