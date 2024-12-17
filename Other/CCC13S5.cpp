#include <bits/stdc++.h>
using namespace std;
int N;

bool isPrime(int N){
    if(N <= 1) return false;
    for(int i = 2; i * i <= N; i++){
        if(N % i == 0)
            return false;
    }
    return true;
}

int fun(int N){
    if(N == 1) return 0;
    else if(isPrime(N)){
        return (N-1) + fun(N-1);
    }else{
        for(int i = 2; i < N; i++){
            if(N%i == 0){
                return fun(i) + fun(N/i);
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N;
    cout << fun(N) << endl;
}