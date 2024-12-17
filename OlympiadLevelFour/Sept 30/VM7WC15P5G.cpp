#include <bits/stdc++.h>
using namespace std;
const int MM = 2003; long long BIT[MM][MM]; int N; int mod = 1e9+7;
void update(int dia, int pos, int val){
    for(int i = pos; i < MM; i+=i&-i) BIT[dia][i]+=val;
}
long long query(int dia, int pos){
    long long ans = 0;
    for(int i = pos; i > 0; i-=i&-i) ans+=BIT[dia][i];
    return ans;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N; int ans = 0;
    for(int i = 0, op, x, y, z; i < N; i++){
        cin >> op >> x >> y >> z;
        if(op==1){
            update(x+y, x, z);
        }else{
            ans=(ans+abs(query(x+y, x)-query(x+y, x-z-1))+mod)%mod;
        }
    }
    cout << ans;
}