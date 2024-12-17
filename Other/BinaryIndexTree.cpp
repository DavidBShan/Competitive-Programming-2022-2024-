#include <bits/stdc++.h>
using namespace std;

const int MM = 1e5+5;
long long bit[MM], freq[MM], arr[MM], n;
void upd(long long bit[], int end, int val){
    for(int i = end; i < MM; i+=i&-i) bit[i] += val;
}
long long qry(long long bit[], int end){
    long long ans = 0;
    for(int i = end; i; i-=i&-i) ans+=bit[i];
    return ans;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N, M; cin >> N >> M;
    for(int i = 1; i <= N; i++) {cin >> arr[i]; upd(bit, i, arr[i]); upd(freq, arr[i], 1);}
    for(int i = 1; i <= M; i++){
        char c; cin >> c;
        if(c == 'C'){
            int x, v; cin >> x >> v;
            upd(freq, arr[x], -1); upd(freq, v, 1);
            upd(bit, x, v-arr[x]); arr[x] = v;
        } else if(c == 'S'){
            int l, r; cin >> l >> r;
            cout << qry(bit, r) - qry(bit, l-1) << '\n';
        } else {
            int x; cin >> x;
            cout << qry(freq, x) << '\n';
        }
    }
}