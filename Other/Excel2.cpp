#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    long long num; cin >> num; string s;
    while(num > 0){
        num--;  char ch = 'A' + (num % 26);
        s = ch + s;num /= 26;
    }
    cout << s;
}