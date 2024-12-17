#include <bits/stdc++.h>
using namespace std;
const int MM = 1e6+3;
int N, D, arr[MM], dp[MM]; deque<int> q;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> D;
    for(int i = 1; i <= N; i++){
        cin >> arr[i];
    }
    dp[1] = arr[1]; q.push_back(1);
    for(int i = 2; i <= N; i++){
        while(!q.empty() && q.front() + D < i){
            q.pop_front();
        }
        dp[i] = dp[q.front()] + arr[i];
        while(!q.empty() && q.back() <= dp[i]){
            q.pop_back();
        }
        q.push_back(i);
    }
    cout << dq[N] << endl;