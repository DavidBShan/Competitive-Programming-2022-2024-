#include <bits/stdc++.h>
using namespace std;
int T;
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> T;
    for(int i = 0, N; i < T; i++){
        cin >> N; int arr[N];
        for(int j = 0; j < N; j++) cin >> arr[j];
        int ans = 0; set<int> difSet, posSet;
        for(int j = 0; j < N; j++){
            difSet.insert(arr[j]);
            for(int k = 0; k < N; k++){
                if(arr[k]>arr[j]) difSet.insert(arr[k]-arr[j]);
                else difSet.insert(arr[j]-arr[k]);
            }
        }
        for(int a: difSet){
            for(int b: difSet){
                for(int c: difSet){
                    posSet.clear();
                    if(a <= b && b <= c){
                        bool flag = true; 
                        posSet.insert(a); posSet.insert(b); posSet.insert(c);
                        posSet.insert(a+b); posSet.insert(a+c); posSet.insert(b+c); posSet.insert(a+b+c);
                        for(int m = 0; m < N; m++){
                            if(posSet.find(arr[m]) == posSet.end()){
                                flag = false;
                                break;
                            }
                        }
                        if(flag) ans++;
                    }
                }
            }
        }
        cout << ans << "\n";
    }
}