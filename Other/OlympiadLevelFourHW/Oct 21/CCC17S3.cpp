#include <bits/stdc++.h>
using namespace std;
const int MM = 2002;
int N, cnt[MM], tot[2*MM], ans=-1, times=-1;
int main(){
    cin >> N;
    for(int i=1, x; i<=N; i++){
        cin >> x; cnt[x]++;
    }
    for(int i = 1; i <= 2000; i++){
        for(int j = i; j <= 2000; j++){
            //cout << i << " " << j << endl;
            if(i == j) {tot[i+j] += cnt[i]/2;}
            else tot[i+j] += min(cnt[i], cnt[j]);
        }
    }
    for(int i = 1; i <= 2*MM; i++){
        if(tot[i] > ans){
            ans = tot[i]; times = 1;
        }else if(tot[i] == ans){
            times++;
        }
    }
    cout << ans << " " << times;
}