#include <bits/stdc++.h>
using namespace std;
const long long MM = 1e5+3;
long long bit[MM]; long long arr[MM]; map<long long, long long> mp;
void upd(long long pos, long long val){
    for(long long i = pos; i < MM; i+=i&-i){
        bit[i]+=val;
    }
}

long long qry (long long pos){
    long long ans = 0;
    for(long long i = pos; i; i-=i&-i){
        ans+=bit[i];
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    long long N; cin >> N;
    for(long long i = 1; i <= N; i++){
        cin >> arr[i]; mp[arr[i]] = 0;
    }
    long long idx = 0, ans = 0;
    for (auto & e: mp){
        e.second=++idx;
    }
    for(long long i = 1; i <= N; i++){
        ans+=i-qry(mp[arr[i]]);
        upd(mp[arr[i]], 1);
    }
    cout << fixed << setprecision(9) << ((double) ans)/N;
}