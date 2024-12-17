#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N; cin >> N;
    int cycles = (N+1)/4;
    cout << 3*(cycles)+(N-cycles-1);
}