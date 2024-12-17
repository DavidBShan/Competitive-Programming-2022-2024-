    #include <bits/stdc++.h>
    using namespace std;
    int N, M, T, sum = 0, ans = 0; vector<pair<int, int>> a;
    int main(){
        ios::sync_with_stdio(0); cin.tie(0);
        cin >> N >> M >> T;
        for(int i = 0; i < N; i++){
            int p, c; cin >> p >> c;
            a.push_back({p, c});
        }
        sort(a.begin(), a.end());
        priority_queue<int, vector<int>, greater<int>> q;
        for(pair<int, int> e: a){
            int p = e.first; int c = e.second;
            if(p*2+T>M) break;
            sum+=c; q.push(c);
            int count = (M-2*p)/T;
            while(q.size()>count){
                sum-=q.top(); q.pop();
            }
            ans = max(ans, sum);
        }
        cout << ans;
    }