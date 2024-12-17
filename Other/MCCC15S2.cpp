#include <bits/stdc++.h>
using namespace std;
const int MM = 100005;
int freq[MM]; int mx = -1;
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N; cin >> N;
    for(int i = 0; i < N; i++){
        int a; cin >> a;
        freq[a]++;
    }
    for(int i = 0; i < MM; i++){ mx = max(mx, freq[i]);}
    cout << mx;
}