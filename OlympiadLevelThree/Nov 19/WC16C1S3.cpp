#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5+2;
typedef pair<int, int> pi;
int N, M, T, ans, sum; vector<pi> a;
int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    cin >> N >> M >> T;
    for(int i=0, p, c; i<N; i++) {
        cin >> p >> c;
        a.push_back({p, c});
    }
    sort(a.begin(), a.end());
    priority_queue<int, vector<int>, greater<int> > q;
    for(pi e : a) {
        int p = e.first, c = e.second;
        if(p*2 + T > M) break;
        sum += c; q.push(c);
        int k = (M - 2*p)/T;
        while(q.size() > k) {
            sum -= q.top(); q.pop();
        }
        ans = max(ans, sum);
    }
    cout << ans << endl;
}