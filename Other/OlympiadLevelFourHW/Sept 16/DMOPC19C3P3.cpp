#include <bits/stdc++.h>
using namespace std;
const int MM = 150003;
int psa = 0, N, bit[MM*2]; long long ans = 0;
void update(int pos, int val){ for(int i = pos+MM; i < 2*MM; i+=i&-i) bit[i] += val; }
int query(int pos){
    int act = 0;
    for(int i = pos+MM; i > 0; i -= i&-i) act+=bit[i];
    return act;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N; cin >> N; update(0, 1);
    for(int i=0, temp; i < N; i++){
        cin >> temp; 
        temp==1?psa++:psa--;
        ans+=query(psa-1);
        update(psa, 1);
    }
    cout << ans;
}