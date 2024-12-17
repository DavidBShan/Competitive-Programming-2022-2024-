#include <bits/stdc++.h>
using namespace std;
const long long MM = 1e4+5;
long long n, mn, arr[MM]; unordered_set<long long> st;

bool check(long long x){
    unordered_set<long long> s;
    for(long long i = 0; i < n; i++) s.insert(arr[i]%x);
    return s.size() <= 3;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n; mn = 4e9+5;
    for(long long i = 0; i < n; i++){ cin >> arr[i]; mn = min(mn, arr[i]); }
    mn = mn/4; sort(arr, arr+n); n = unique(arr, arr+n)-arr;
    if(n <= 3){
        long long sm = 0;
        for(long long i = 1; i <= mn; i++) sm += i;
        cout << sm; return 0;
    }else{
        for(long long i = 0; i < 4; i++){
            for(long long j = i+1; j < 4; j++){
                long long dif = arr[j]-arr[i];
                for(long long k = 1; k*k<=dif && k<=mn; k++){
                    if(dif%k) continue;
                    if(!st.count(k) && check(k)) st.insert(k);
                    if(dif/k <= mn  && !st.count(dif/k) && check(dif/k)) st.insert(dif/k);
                }
            }
        }
    }
    long long ans = 0;
    for(long long num: st){
        ans+=num;
    }
    cout << ans;
}