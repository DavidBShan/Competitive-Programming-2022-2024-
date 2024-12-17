#include <bits/stdc++.h>
using namespace std;

int main(){
    string A, B;
    cin >> A >> B; long long ans = 0;
    for(int i = 0; i < A.length(); i++){
        for(int j = 0; j < B.length(); j++){
            ans+=(A[i]-48)*(B[j]-48);
        }
    }
    cout << ans;
}