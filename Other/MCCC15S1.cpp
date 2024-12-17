#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    long long P, U, R1, R2;
    cin >> P >> U >> R1 >> R2;
    long long num = 0;
    for(long long i = 1; i <= U; i++){
        for(long long j = 1; j+i <= U; j++){
            long long k = U-i-j;
            if(k<=0) continue;
            if(2*i+j-k == P){
                if(i * R1 == j * R2) num++;
                else if(i * R2 == j * R1) num++;
                else if(j * R2 == k * R1) num++;
                else if(j * R1 == k * R2) num++;
                else if(k * R1 == i * R2) num++;
                else if(k * R2 == i * R1) num++;
            }
        }
    }
    cout << num;
}