#include <bits/stdc++.h>
using namespace std;

int main(){
    long long N, maxVal = -1, one; cin >> N;
    for(int two = 0; two <= N/2; two++){
        one = N-2*two ;
        maxVal = max(maxVal, two*((one*(one-1))/2));
    }
    cout << maxVal;
}