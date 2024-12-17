#include <bits/stdc++.h>
using namespace std;
const int MM = 252;
int psa[MM][MM], W, H, N, ans = -1; ;
int main(){
    cin >> W >> H >> N; 
    //memset(psa, 0, sizeof psa);
    for(int i = 1; i <= W; i++){
        for(int j = 1, temp; j <= H; j++){
            cin >> temp;
            psa[i][j] = psa[i-1][j]+psa[i][j-1]-psa[i-1][j-1]+temp;
        }
    }
    for(int h = 1; h <= H; h++){
        int w = min(W, N/h);
        for(int c1 = 1; c1+w-1<=W; c1++){
            for(int r1 = 1; r1+h-1<=H; r1++){
                int r2 = r1+h-1, c2 = c1+w-1;
                ans = max(ans, psa[c2][r2]-psa[c1-1][r2]-psa[c2][r1-1]+psa[c1-1][r1-1]);
            }
        }
    }
    cout << ans;
}