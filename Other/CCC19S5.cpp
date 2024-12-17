#include <bits/stdc++.h>
using namespace std;
const int MM =  3005;
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N, K; cin >> N >> K;
    int arr[MM][MM];
    memset(arr, 0, sizeof(arr));
    for(int i = 1; i <= N; i++)
        for(int j = 1; j <= i; j++)
            cin >> arr[i][j];
            
    for(int i = 2; i <= K; i++){
        for(int j = 1; j <= (N-i+1); j++){
            for(int k = 1; k <= j; k++){
                arr[j][k] = max(arr[j][k], max(arr[j+1][k], arr[j+1][k+1]));
            }
        }
    }
    long long sum = 0;
    for(int i = 1; i <= N-K+1; i++){
        for(int j = 1; j <= i; j++){
            sum += arr[i][j];
            //cout << i << " " << j << " " << arr[i][j] << endl;
        }
    }
    cout << sum;
}