#include <bits/stdc++.h>
using namespace std;
int main(){
    int n; cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr, arr+n);
    if(n%2 == 0){
        for(int i = 0; i < n/2; i++){
            cout << arr[n/2-i-1] << " ";
            cout << arr[n/2+i] << " ";
        }
    }
    if(n%2 == 1){
        for(int i = 0; i < n/2; i++){
            cout << arr[n/2-i] << " ";
            cout << arr[n/2+1+i] << " ";
        }
        cout << arr[0];
    }
}