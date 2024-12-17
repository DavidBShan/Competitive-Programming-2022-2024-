#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N, K; cin >> N >> K; 
    vector<int> A(N+1);
    for(int i = 1; i <= N-K; i++){
        A[i] = i+1;
    }
    A[N-K+1] = 1;
    for(int i = N-K+2; i <= N; i++){
        A[i] = i;
    }
    for(int i = 1; i <= N; i++){
        cout << A[i] << " ";
    }
}