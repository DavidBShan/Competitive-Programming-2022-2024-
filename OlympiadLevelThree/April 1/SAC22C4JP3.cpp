#include <bits/stdc++.h>
using namespace std;
#define PI 3.14159265

int main(){
    int N, A, ans = 0, x, y, degrees, ansInd = -1;
    cin >> N >> A;
    for(int i = 1; i <= N;i++){
        cin >> x >> y;
        degrees = (atan2 (y,x) * 180 / PI)>0?(atan2 (y,x) * 180 / PI):(atan2 (y,x) * 180 / PI)+360;
        if((abs(A-ans)>abs(A-degrees))){
            ans= degrees; ansInd = i;
        }else if((abs(A-ans)>abs(A-degrees-360))){
            ans = degrees+360; ansInd = i;
        }
    }
    cout << ansInd;
}