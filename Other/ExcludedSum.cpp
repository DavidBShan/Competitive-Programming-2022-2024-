#include <bits/stdc++.h>
using namespace std;
long long A, B;
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> A >> B; set<long long> s;
    long long sum = (B+1)*(B)/2;
    for(long long i = 0; i < A; i++){
        long long x; cin >> x;
        if (s.count(x) == 0 && x <= B) {
            sum -= x; s.insert(x);
        }
    }
    cout << sum;
}