#include <bits/stdc++.h>
using namespace std;
string S; int K;
bool check(int len, int psa[]){
    for(int i = 0; i < S.length()-len+1; i++){
        if(psa[i+len]-psa[i]<=K)return true;
    }
    return false;
}
int main(){
    int ans; cin >> S >> K; int psa[S.length()+1];psa[0] = 0;
    for(int i = 1; i <= S.length();i++){
        if(S.at(i-1)=='1') psa[i]=psa[i-1];
        else psa[i]=psa[i-1]+1;
    }
    int low = 0, high = S.length(), mid;
    while(low<=high){
        mid = (low+high)/2;
        if(check(mid,psa)){low = mid+1; ans = mid;} 
        else high = mid-1;
    }
    cout << ans;
}