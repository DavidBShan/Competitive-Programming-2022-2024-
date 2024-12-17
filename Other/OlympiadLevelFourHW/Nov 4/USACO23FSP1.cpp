#include <bits/stdc++.h>
using namespace std;
const int MM = 103;
long long T, N, tC, tM, a[MM], b[MM], c[MM];
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> T;
    for(int t = 1; t<=T; t++){
        cin >> N >> tC >> tM;
        for(int i = 1; i <= N; i++) cin >> a[i] >> b[i] >> c[i];
        long long lo = 0, hi = tC+tM-2, ans=1e18;
        while(lo<=hi){
            long long mid = (lo+hi)/2, mn=max(0LL, mid-tM+1), mx=min(mid, tC-1);
            for(int i = 1; i <= N; i++){
                long long val = a[i]*tC+b[i]*tM-c[i];
                if(val<=0) continue;
                val-=b[i]*mid;
                if(a[i]-b[i]==0){
                    if(val<=0) continue;
                    mn=mx+1; break;
                }
                if((a[i]-b[i]>0)){
                    long long K = ceil((double)(a[i]*tC+b[i]*tM-b[i]*mid-c[i])/(a[i]-b[i]));
                    mn=max(mn,K);
                }
                if((a[i]-b[i])<0){
                    long long K = floor((double)(a[i]*tC+b[i]*tM-b[i]*mid-c[i])/(a[i]-b[i]));
                    mx=min(mx, K);
                }
            }
            if(mn<=mx){
                ans=min(ans, mid);
                hi=mid-1;
            }else{
                lo=mid+1;
            }
        }
        cout << ans << "\n";
    }
}