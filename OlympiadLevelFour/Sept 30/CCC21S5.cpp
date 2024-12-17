#include <bits/stdc++.h>
using namespace std;
const int MM = 1.5e5+3, LOG = __lg(MM);
int N, M, x[MM], y[MM], z[MM], a[MM], sparseTable[LOG+1][MM], dif[17][MM];
int query(int l, int r){
    int k = log2(r - l + 1);
    return gcd(sparseTable[k][l], sparseTable[k][r-(1<<k)+1]);
}

int main(){

    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    for(int i = 1; i <= M; i++){
        cin >> x[i] >> y[i] >> z[i];
        dif[z[i]][x[i]]++; dif[z[i]][y[i]+1]--;
    }
    for(int i = 1; i <= N; i++){
        a[i] = 1;
        for(int j = 1; j <= 16; j++){
            dif[j][i] += dif[j][i-1];
            if(dif[j][i]) a[i] = lcm(a[i], j);
        }
        sparseTable[0][i] = a[i];
    }
    for(int k=1; k<=LOG; k++)
        for(int i=1; i+(1<<k-1)<=N; i++)
            sparseTable[k][i] = gcd(sparseTable[k-1][i], sparseTable[k-1][i+(1<<k-1)]);
    for(int i = 1; i <= M; i++){
        if(query(x[i], y[i]) != z[i]){
            cout << "Impossible\n"; return 0;
        }
    }
    for(int i = 1; i <= N; i++){
        cout << a[i] << " ";
    }
}