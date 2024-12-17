#include <bits/stdc++.h>
using namespace std;
const int MM = 2e5+5;
long long N, K, ans = 0, psa[MM]; deque<long long> q;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> K; 
    for(int i = 1; i <= N; i++){
        cin >> psa[i]; psa[i+N] = psa[i];
    }
    q.push_back(0);
    for(int i = 1; i <= 2*N; i++){
        psa[i] += psa[i-1];
        while(!q.empty() && q.front()+K < i){
            q.pop_front();
        }
        while(!q.empty() && psa[q.back()] >= psa[i]){
            q.pop_back();
        }
        ans = max(ans, psa[i] - psa[q.front()]);
        q.push_back(i);
    }
    cout << ans << endl;
}