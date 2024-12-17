#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5+5;
int main(){
    int N, K; cin >> N >> K;
    long long arr[MM]; map<long long, long long> mp;
    for(int i = 0; i < N; i++){
        cin >> arr[i];
    }
    long long ans = 0;
    for(int l = 0, r = 0, temp = 0; r < N; r++){
        temp = mp[arr[r]]++;
        while(mp.size() >= K){
            ans += N-r;
            mp[arr[l]]--;
            if(mp[arr[l]]<=0) mp.erase(arr[l]);
            l++;
        }
    }
    cout << ans;
}