#include <bits/stdc++.h>
using namespace std;
const int MM = 1e6+2;
int a[MM], last; deque<int> q;
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N, M; long long K; cin >> N >> M >> K;
    if(K < N) {cout << -1; return 0;}
    K-=N; a[1] = 1; q.push_back(1); last = 1;
    for(int idx=2; idx <= N; idx++){
        if(K >= q.size()){
            last++;
            if(last <= M){
                K-=last-1;
                a[idx] = last; q.push_back(last);
            }else{
                int x = q.front(); q.pop_front();
                K -= M - 1;  a[idx] = x;  q.push_back(x);
            }
        }else{
            int pos = (int)q.size() - 1 - K;
            a[idx] = q[pos]; K = 0;  q.push_back(a[idx]);
        }
    }
    if(K > 0) { cout << "-1\n"; return 0;}
    for(int i=1; i<=N; i++) cout << a[i] << " ";
}