#include <bits/stdc++.h>
using namespace std;
const int MM = 5003;
int cropLength[MM][MM], mountain[MM], ans[MM];

int fun(int l, int r){
    if(l>=r) return 0;
    if(cropLength[l][r]!=-1) return cropLength[l][r];
    return cropLength[l][r] = abs(mountain[l]-mountain[r])+fun(l+1,r-1);
}

int main(){
    int N; cin >> N;
    memset(cropLength, -1, sizeof(cropLength));
    fill(ans, ans+MM,1e9);
    for(int i = 1; i <= N;i++) cin >> mountain[i];
    for(int l = 1; l <= N;l++){
        for(int r = l; r <=N;r++){
            ans[r-l+1] = min(ans[r-l+1],fun(l,r));
        }
    }
    for(int i = 1; i <= N;i++){
        cout << ans[i] << " ";
    }
}