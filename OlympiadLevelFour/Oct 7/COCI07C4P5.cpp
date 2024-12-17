#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5+5;
int N; vector<pair<int, int>> vec, subseq; int pre[MM]; vector<int> ans;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    for(int i = 0, x, y; i < N; i++){
        cin >> x >> y; vec.push_back({x, -y});
    }
    sort(vec.begin(), vec.end());
    subseq.push_back({-1e9, -1});
    for(int i = 0; i < vec.size(); i++){
        int sec = vec[i].second;
        int loc = upper_bound(subseq.begin(), subseq.end(), make_pair(sec, i)) - subseq.begin();
        if(loc == subseq.size()) subseq.push_back({sec, i});
        else subseq[loc] = {sec, i};
        pre[i] = subseq[loc-1].second;
    }
    for(int i = subseq.back().second; i!=-1; i = pre[i]) ans.push_back(i);
    reverse(ans.begin(), ans.end());
    cout << ans.size() << "\n";
    for(int i : ans) cout << vec[i].first << " " << -vec[i].second << "\n";
}