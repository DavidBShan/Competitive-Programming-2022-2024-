#include <bits/stdc++.h>
using namespace std;

int main(){
    int N, T, M; cin >> N>> T >> M;
    int difArr[N+1]; memset(difArr,0,sizeof difArr); difArr[1] = T; int cur = 0, countF = 0;
    for(int i = 0, temp; i < M;i++){
        cin >> temp;
        if(temp == 1) difArr[2]--;
        else if(temp==N){ difArr[1]--;difArr[N]++;}
        else {difArr[1]--;difArr[temp]++; difArr[temp+1]--;}
    }
    for(int i = 0; i < N;i++){
        cur+=difArr[i];
        if(cur>0) countF++;
    }
    cout << countF;
}