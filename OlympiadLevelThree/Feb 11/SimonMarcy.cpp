#include <bits/stdc++.h>
using namespace std;
int C, M, priN, songN;
int main(){
    cin >> C >> M; int maxPri[1002];
    fill(maxPri, maxPri+1002, 0);
    for(int i = 0; i < C;i++){
        cin >> priN >> songN;
        for(int j = M;j >= songN;j--){
            maxPri[j] = max(maxPri[j], maxPri[j-songN]+priN);
        }
    }
    cout << maxPri[M];
}