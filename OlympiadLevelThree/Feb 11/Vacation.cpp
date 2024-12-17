#include <bits/stdc++.h>
using namespace std;

int main(){
    int N; cin >> N;
    int maxDays[N+1][3];
    maxDays[0][0] = 0; maxDays[0][1] = 0; maxDays[0][2] = 0;
    for(int i = 1, a, b, c; i <= N;i++){
        cin >> a >> b >> c;
        maxDays[i][0] = max (maxDays[i-1][1],maxDays[i-1][2])+ a;
        maxDays[i][1] = max (maxDays[i-1][0],maxDays[i-1][2])+ b;
        maxDays[i][2] = max (maxDays[i-1][0],maxDays[i-1][1])+ c;
    }
    cout << max(maxDays[N][0],max(maxDays[N][1],maxDays[N][2]));
}