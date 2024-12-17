#include <iostream>
#include <algorithm>
using namespace std;

const int MM = 3005;
int arr[MM][MM], BIT[MM][MM], N, K;
long long ans = 0; int cnt[MM];

inline void updateBIT(int x, int y, int val){
    for (int i = x; i <= N; i += i & -i){
        for (int j = y; j <= N; j += j & -j){
            BIT[i][j] = max(BIT[i][j], val);
        }
    }
}

inline int getMax(int x, int y){
    int mx = 0;
    for (int i = x; i > 0; i -= i & -i){
        for (int j = y; j > 0; j -= j & -j){
            mx = max(BIT[i][j], mx);
        }
    }
    return mx;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> K;
    for (int i = 1; i <= N; i++){
        for (int j = 1; j <= i; j++){
            cin >> arr[i][N-j+1];
        }
    }

    for(int i = 1; i <= N; i++){
        for(int j = N; j>= N-i+1; j--){
            int col = N-cnt[j]++;
            updateBIT(j, col, arr[j][col]);
            if(N-j+1 >= K) ans += getMax(j+K-1, col);
        }
    }
    cout << ans << '\n';
}