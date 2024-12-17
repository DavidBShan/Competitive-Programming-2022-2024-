#include <bits/stdc++.h>
using namespace std;

int main(){
    int A, B, C, K, ans;
    cin >> A >> B >> C >> K;
    if(A<=K){
        K-=A;
        ans+=A;
        if(B<=K){
            K-=B;
            if(C<=K){
                K-=C;
                ans-=C;
            }else{
                ans-=K;
            }
        }
    }else{
        ans+=K;
    }
    cout << ans;
}