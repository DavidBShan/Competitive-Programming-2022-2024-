#include <bits/stdc++.h>
using namespace std;
const int MM = 2e5+5;
int N, K, T; vector<int> active;
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> K >> T;
    int curActive = 0;
    for(int i = 1, temp; i <= K; i++){
        cin >> temp; active.push_back(temp);
    }
    for(int i = 1; i <= N; i++){
        if(curActive+1 < active.size() && active[curActive+1]>=i) curActive++;
        int d = (curActive+1 < active.size()) ? active[curActive+1]-active[curActive] : 1;
        int pos =  (i + static_cast<int>(ceil( static_cast<double>(T - (i - active[curActive])) / d)) * d) % N; 
        cout << pos;
    }
}