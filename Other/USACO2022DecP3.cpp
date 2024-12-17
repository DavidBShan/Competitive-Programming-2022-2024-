#include <bits/stdc++.h>
using namespace std;
const int MM = 303;
int N; int arr[MM][MM], ans[MM];

bool func(int i){
    int mx = -1e9, mn = 1e9;
    for(int j = i; j <= N; j++){
        mx = max(mx, ans[j]);
        mn = min(mn, ans[j]);
        if(mx-mn != arr[i][j]) return false;
    }
    return true;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N;
    for(int i = 1; i <= N; i++){
        for(int j = i; j <= N; j++){
            cin >> arr[i][j];
        }
    }
    ans[N] = 0;
    for(int i = N-1; i>=1; i--){
        ans[i] = ans[i+1] + arr[i][i+1];
        if(!func(i)) ans[i] = ans[i+1] - arr[i][i+1];
    }

    for(int i = 1; i <= N; i++){
        cout << ans[i] << " ";
    }
}