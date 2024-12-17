#include <bits/stdc++.h>
using namespace std;
string A, B;
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> A >> B;
    if (A == B) {
        cout << "Yes\n";
        return 0;
    } 
    int dif = 0;
    if (A.size() != B.size() + 1) {
        cout << "No\n";
        return 0;
    }
    for (int i = 0; i < A.size(); i++) {
        if (A[i + dif] != B[i]) dif++;
        if (A[i + dif] != B[i]) dif++;
        if (dif > 1) {
            cout << "No\n";
            return 0;
        }
    }
    cout << "Yes\n";
}