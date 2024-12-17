#include <bits/stdc++.h>
using namespace std;

int main(){
    int N, D; cin >> N >> D; long long psa[N+1], ans = 0, leftBound = 1, rightBound = N; psa[0] = 0;
    for(int i = 1, temp; i <= N; i++){
        cin >> temp;
        psa[i] = psa[i-1] + temp;
    }
    for(int i = 0, split; i < D; i++){
        cin >> split;
        long long left = psa[leftBound+split-1]-psa[leftBound-1];
        long long right = psa[rightBound]-psa[leftBound+split-1]; //def right
        if(left>=right){
            leftBound+=split;
        }else{
            rightBound=leftBound+split-1;
        }
        cout << max(left, right)<<endl;
    }
}