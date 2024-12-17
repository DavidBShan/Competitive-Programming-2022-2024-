#include <iostream>
#include <cmath>
using namespace std;
int main() {
    long long n; 
    cin >> n;
    long long lg = 0;
    while ((1LL << (lg + 1)) <= n) {
        lg++;
    }
    long long dif = n - (1LL << lg);
    cout << dif * (lg + 2) + lg * (1LL << lg) << endl;
}
