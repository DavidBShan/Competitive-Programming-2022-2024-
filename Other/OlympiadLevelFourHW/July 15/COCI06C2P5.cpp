#include <bits/stdc++.h>
using namespace std;
const int MM = 403;
int R, C, psa[MM][MM], ans = -1;
int main(){
    cin >> R >> C; char temp;
    for(int i = 1; i <= R; i++){
        for(int j = 1; j <= C; j++){
            cin >> temp;
            psa[i][j]=psa[i-1][j]+psa[i][j-1]-psa[i-1][j-1]+(temp=='X');
        }
    }
    for(int r0 = 1; r0 <= R; r0++){
        for(int r1 = r0; r1 <= R; r1++){
            int st = 1;
            for(int j = 1; j <= C; j++){
                int sum = psa[r1][j] - psa[r1][st-1] - psa[r0-1][j] + psa[r0-1][st-1];
                if(sum==0) ans = max(ans, 2*(r1-r0+1)+2*(j-st+1));
                else st = j+1;
            }
        }
    }
    cout << ans-1;
}