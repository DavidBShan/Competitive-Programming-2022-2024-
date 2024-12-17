#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int arr[n][n];
    memset(arr, 0, sizeof(arr));
    for(int i=1; i<n-1; i++){
        for(int j=2; j<n-2; j+=5){
            arr[i][j]=1;
        }
    }
    for(int ri=1; i<n-1; i++){
        arr[i][n-3]=1;
    }
    for(int i=0; i<n; i++){
        if(arr[1][i] && !arr[1][i+1] && !arr[1][i-1]){
            arr[1][i-2]=1;
            arr[n-2][i-2]=1;
        }
    }
    for(int i=0; i<n-4; i++){
        if(arr[1][i] && arr[1][i+4] && ((i-2)%5)){
            arr[1][i]=0;
            arr[n-2][i]=0;
        }
    }
    if(arr[1][n-4]){
        for(int i=3; i<n-4; i+=3){
            arr[i][n-4]=0;
            arr[i][n-3]=0;
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n-1; j++){
            cout << arr[i][j] << " ";
        }
        cout << arr[i][n-1] << "\n";
    }
    return 0;
}