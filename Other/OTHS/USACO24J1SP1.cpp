#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5+5;
int f[MM], arr[MM], N, Q, C, fin[MM];
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while(T--){
        cin >> N >> Q >> C;
        memset(arr, 0, sizeof(arr));
        for(int i = 1; i <= N; i++) cin >> arr[i];
        memset(f, 0, sizeof(f)); memset(fin, 0, sizeof(fin));
        for(int i = 1, a, h; i <= Q; i++){
            cin >> a >> h;
            f[h] = 1;
            for(int j = a+1; j < h; j++){
                f[j] = -1;
            }
        }
        int lastEmptyInd = 0, lastMax = 0;
        for(int i = 1; i <= N; i++){
            if(arr[i] == 0){
                if(f[i] == 1){
                    lastEmptyInd = i;
                    fin[i] = lastMax+1;
                    lastMax = max(lastMax, fin[i]);
                }else if(f[i] == -1){
                    fin[i] = 1;
                }else{
                    lastEmptyInd = i;
                    fin[i] = 1;
                }
            }else{
                if(f[i] == 1 && arr[i] <= lastMax){
                    cout << -1;
                    return 0;
                }else if(f[i] == -1 && arr[i] > lastMax){
                    fin[lastEmptyInd] = arr[i];
                    return 0;
                }
                fin[i] = arr[i];
                lastMax = max(lastMax, arr[i]);
            }
        }
        lastMax = 0;
        for(int i = 1; i <= N; i++){
            if(fin[i] <= C){
                cout << -1; return 0;
            }else if(fin[i] = 1){
                if(fin[i] > lastMax){
                    cout << -1; return 0;
                }
            }else if(fin[i] == -1){
                if(fin[i] <= lastMax){
                    cout << -1; return 0;
                }
            }else{
                lastMax = max(lastMax, fin[i]);
            }
        }
        for(int i = 1; i <= N; i++){
            cout << fin[i] << " ";
        }
    }
}