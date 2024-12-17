#include <bits/stdc++.h>
using namespace std;
const int MM = 1005;
long long psa[MM][MM];
int main(){
    int M, N, r, c, x, r1, c1, r2, c2;
    cin >> M >> N;
    cin >> r >> c >> x;
    while(r!=0){
        psa[r][c] = (((r+c)%2==0)?1:-1)*x;
        cin >> r >> c >> x;
    }
    for(int i=1; i<=M; i++)
        for(int j=1; j<=N; j++)
            psa[i][j] += psa[i-1][j] + psa[i][j-1] - psa[i-1][j-1];
    cin >> r1 >> c1 >> r2 >> c2;
    while(r1!=0){
        long long sum = psa[r2][c2] - psa[r1-1][c2] - psa[r2][c1-1] + psa[r1-1][c1-1];
        cout << ((r1+c1)%2 == 0? sum : -sum) << "\n";
        cin >> r1 >> c1 >> r2 >> c2;
    }
}