#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5+5;

int N, S, psa[MM], ans[MM];
int main(){
    cin >> N >> S;
    for(int i = 1; i <= N; i++){
        cin >> psa[i]; psa[i] += psa[i-1];
    }
    int lft = 1, rit = 0;
    for(int i=1; i<=N; i++) {
        while(lft <= i-1 && psa[i-1] - psa[lft-1] > S){
            lft++;
        }
        while(rit+1 <= N && psa[rit+1] - psa[i-1] <= S){
            rit++;
        }
        int len = min(i-lft, rit-i+1);
        ans[i-len] = max(ans[i-len], len);
    }
    for(int i = 1; i <= N; i++){
        ans[i] = max(ans[i], ans[i-1] - 1);
        cout << 2 * ans[i] << "\n";
    }
}