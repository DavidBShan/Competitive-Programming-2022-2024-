#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; int sum = 0; int max = -1;
    cin >> n;   
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        sum += x;
        if(x > max) max = x;
    }
    cout << (sum-max)/(n-1);
}