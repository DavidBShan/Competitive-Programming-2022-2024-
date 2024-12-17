#include <bits/stdc++.h>
using namespace std;
vector<long long> house;
const long long MM = 1e6;
long long H, k;
long long check(long long r) {
    long long ret = H, d = 2 * r;
    for (long long st = 0; st < house.size() && house[st] <= house[0] + d; st++) {
        long long cnt = 1;
        for (long long nxt = st + 1, lst = house[st]; nxt < house.size() && house[nxt] + d - MM < house[st]; nxt++) {
            if (house[nxt] > lst) {
                lst = house[nxt] + d;
                cnt++;
            }
        }
        ret = min(ret, cnt);
    }
    return ret;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> H; house.resize(H);
    for(long long i = 0; i < H; i++){
        cin >> house[i];
    }
    sort(house.begin(), house.end());
    cin >> k; 
    long long low = 0, high = MM, ans = 0;
    while(low <= high){
        long long mid = (low+high)/2;
        if(check(mid) <= k){
            ans = mid;
            high = mid-1;
        } else {
            low = mid+1;
        }
    }
    cout << ans << endl;
}