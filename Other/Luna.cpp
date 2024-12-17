#include <bits/stdc++.h>
using namespace std;
const long long MM = 1e6+3;
long long n, last[MM], bit[MM]; long long ans = 0;
void update(long long pos, long long val){
    for(long long i = pos; i <= 2*n; i+=i&-i) bit[i]+=val;
}

long long query(long long pos){
    long long sum = 0;
    for(long long i = pos; i > 0; i-=i&-i) sum+=bit[i];
    return sum;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n; 
    for(long long i = 1, x; i <= 2*n; i++){
        cin >> x; 
        if(!last[x]) {
            update(i, 1); last[x] = i;
        } else{
            ans+= query(i) - query(last[x]);
            update(last[x], -1);
        }
    }
    cout << ans + n;
}