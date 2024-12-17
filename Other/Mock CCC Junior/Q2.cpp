#include <bits/stdc++.h>
using namespace std;
double RA, RB;

double getCurExpected(){
    return 1/(pow(10, ((RB-RA)/400)) + 1);
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    double N, K, A, B; cin >> N >> A >> B >> K;
    RA = A, RB = B; double total = A+B;
    for(int i = 0; i < N; i++){
        char temp; cin >> temp;
        double expected = getCurExpected();
        if(temp == 'W'){
            RA += (1-expected)*K;
        }else if(temp == 'L'){
            RA += (0-expected)*K;
        }else{
            RA += (0.5-expected)*K;
        }
        RB = total-RA;
        cout << fixed << setprecision(1) << RA << " " << RB << "\n";
    }
}