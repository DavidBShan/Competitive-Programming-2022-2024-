#include <bits/stdc++.h>
using namespace std;
int N, M, K, Q;
const int MM = 5003;
int dif[MM][MM]; long long psa[MM][MM];

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M >> K;
    for(int i= 1, x1, x2, y1, y2; i <= K;i++){
        cin >> x1 >> y1 >> x2 >> y2; x2++; y2++;
        dif[x1][y1]++; dif[x2][y1]--; dif[x1][y2]--; dif[x2][y2]++;
    }
    for(int i = 1; i <=N;i++){
        for(int j = 1; j <= M; j++){
            dif[i][j]+=dif[i-1][j]+dif[i][j-1]-dif[i-1][j-1];
            psa[i][j]=dif[i][j] + psa[i-1][j] + psa[i][j-1] - psa[i-1][j-1];
        }
    }
    cin >> Q;
    for(int i = 0, a, b, c, d; i < Q; i++){
        cin >> a >> b >> c >> d; a--; b--;
        cout << psa[c][d]-psa[c][b]-psa[a][d]+psa[a][b]<<endl;
    }
}