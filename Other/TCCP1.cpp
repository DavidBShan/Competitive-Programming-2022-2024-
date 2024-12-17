#include <bits/stdc++.h>
using namespace std;
const int MM = 1e6+5;
bool arr[MM];
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; int total = 0; cin >> n;
    int threshold = n/2+1;
    //cout << threshol/d << '\n';
    for(int i = 1; i <= n; i++){
        char temp;
        cin >> temp; total += temp=='Y'?1:0;
        if(temp == 'Y')arr[i] = 1;
        else arr[i] = 0;
    }
    for(int i = 1; i <= n; i++){
        if(total >= threshold){
            cout << "YES"; return 0;
        }
        if(total >= i && arr[i] == 0){
            total++; arr[i] = 1;
        }
    }
    cout << "NO";
}