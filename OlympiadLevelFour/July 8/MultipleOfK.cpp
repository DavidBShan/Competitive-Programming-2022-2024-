#include<bits/stdc++.h>
using namespace std;
const long long MM = 1e6+2;

int main(){
    long long N, K, temp, psa = 0, ans = -1;
    cin >> N >> K;
    long long rem[MM];
    fill(rem, rem+MM, -1);
    rem[0] = 0;
    for(long long i = 1; i <= N; i++){
        cin >> temp; psa = (psa+temp)%K;
        if(rem[psa]!=-1){
            ans = max(ans, i-rem[psa]);
        }else{
            rem[psa]=i;
        }
    }
    cout << ans;
}