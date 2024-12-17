#include <bits/stdc++.h>
using namespace std;
int arr[52][52], dp[52][52][52][52], n, m;

int rec(int x1, int y1, int x2, int y2){
    if(x1 == x2 && y1 == y2) return 0;
    if(dp[x1][y1][x2][y2] != -1) return dp[x1][y1][x2][y2];
    int &ret = dp[x1][y1][x2][y2];
    ret = 1e9;
    int val = arr[x2][y2] - arr[x1-1][y2] - arr[x2][y1-1] + arr[x1-1][y1-1];
    for(int i = x1; i < x2; i++){
        ret = min(ret, rec(x1, y1, i, y2) + rec(i+1, y1, x2, y2) + val);
    }
    for(int i = y1; i < y2; i++){
        ret = min(ret, rec(x1, y1, x2, i) + rec(x1, i+1, x2, y2) + val);
    }
    return dp[x1][y1][x2][y2] = ret;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    memset(dp, -1, sizeof(dp)); memset(arr, 0, sizeof(arr));
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> arr[i][j];
            arr[i][j] += arr[i-1][j] + arr[i][j-1] - arr[i-1][j-1];
        }
    }
    cout << rec(1, 1, n, m);
}