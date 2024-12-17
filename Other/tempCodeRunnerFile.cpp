#include <bits/stdc++.h>
using namespace std;
long long squares[58];
int main() {
    long long n; cin >> n;
    for (int i = 1; i <= 57; i++){
        squares[i] = i*pow(2, i);
    }
    long long lg = log2(n);
    long long dif = n - pow(2, lg);
    cout << dif * (lg + 2) + squares[lg] << endl;
}