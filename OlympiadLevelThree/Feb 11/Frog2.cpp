#include <bits/stdc++.h>
using namespace std;
int main(){
    int N, K; cin >> N >> K;
    int stoneOrg[N]; int stoneSum[N];
    fill(stoneSum,stoneSum+N,INT_MAX);
    for(int i = 0; i < N;i++){  
        cin >> stoneOrg[i];
    } stoneSum[0] = 0;
    for(int i = 1; i < N;i++){
        for(int j = i-1; j >=max(0,i-K);j--){
            stoneSum[i] = min(stoneSum[i],stoneSum[j]+abs(stoneOrg[i]-stoneOrg[j]));
        }
    }
    cout << stoneSum[N-1];
}