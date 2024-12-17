#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    double a, b, c;
    cin >> a >> b >> c;
    cout << fixed << setprecision(2) << (a/40000 + b/60000 + c/70000)*60 << endl;
}