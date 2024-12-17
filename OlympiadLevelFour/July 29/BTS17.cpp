#include <bits/stdc++.h>
using namespace std;

int N, M, J;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> N >> M >> J; 
    if(J>N) {cout << "0"; return 0;}
    priority_queue<int, vector<int>, greater<int>> q; vector<pair<int, int>> vec;
    for(int i = 0, p, t; i < M; i++){
        cin >> p >> t;
        vec.push_back({t, p});
    }
    sort(vec.begin(), vec.end());
    int cur = 0;
    for(pair<int, int> pi: vec){
        int t = pi.first, p = pi.second;
        q.push(p);
        while(!q.empty() && q.top() <= cur + J){
            if(q.top()>cur) cur = q.top();
            q.pop();
        }
        if(cur+J>N){
            cout << t << "\n";
            return 0;
        }
    }
    cout << "-1\n";
}