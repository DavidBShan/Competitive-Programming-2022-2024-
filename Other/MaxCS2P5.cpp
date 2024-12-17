#include <bits/stdc++.h>
using namespace std;
int q; vector<int> st;

void update(int node, int start, int end, int idx, int val) {
    if (start == end) {
        st[node] += val;
    } else {
        int mid = (start + end) / 2;
        if (idx <= mid) update(2 * node, start, mid, idx, val);
        else update(2 * node + 1, mid + 1, end, idx, val);
        st[node] = st[2 * node] + st[2 * node + 1];
    }
}

int query(int node, int start, int end, int l, int r) {
    if (start > r || end < l) return 0;
    if (l <= start && end <= r) return st[node];
    int mid = (start + end) / 2;
    return query(2 * node, start, mid, l, r) + query(2 * node + 1, mid + 1, end, l, r);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> q; vector<pair<int, tuple<int ,int, int>>> vec; vector<int> allCoord;
    while (q--) {
        int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
        if(x1 == x2){ // vertical
            vec.push_back({x1, {1, y1, y2}});
            allCoord.push_back(x1);
            allCoord.push_back(y1);
            allCoord.push_back(y2);
        }else if(y1 == y2){
            vec.push_back({x1, {0, y1, y2}});
            vec.push_back({x2, {2, y1, y2}});
            allCoord.push_back(x1);
            allCoord.push_back(x2);
            allCoord.push_back(y1);
        }
    }
    sort(vec.begin(), vec.end()); sort(allCoord.begin(), allCoord.end());
    map<int, int> mp; int cnt = 1;
    for (int i = 0; i < allCoord.size(); i++) {
        if (!mp[allCoord[i]]) mp[allCoord[i]] = cnt++;
    }
    long long ans = 0;
    st.resize(4 * cnt);
    st.assign(4 *cnt, 0);
    for (int i = 0; i < vec.size(); i++) {
        if (get<0>(vec[i].second) == 0) {
            update(1, 1, cnt, mp[get<1>(vec[i].second)], 1);
            //cout << "START" << get<1>(vec[i].second) << " " << get<2>(vec[i].second) << " " << query(1, 1, cntY, mpY[get<1>(vec[i].second)], mpY[get<2>(vec[i].second)]) << endl;
        } else if (get<0>(vec[i].second) == 2) {
            update(1, 1, cnt, mp[get<2>(vec[i].second)], -1);
            //cout << "END" << get<1>(vec[i].second) << " " << get<2>(vec[i].second) << " " << query(1, 1, cntY, mpY[get<1>(vec[i].second)], mpY[get<2>(vec[i].second)]) << endl;
        } else {
            ans+= query(1, 1, cnt, mp[get<1>(vec[i].second)], mp[get<2>(vec[i].second)]);
            // cout << "HUH" << mpY[get<1>(vec[i].second)] << " " << mpY[get<2>(vec[i].second)];
            // cout << "DAMN" << query(1, 1, cntY, 0, 3) << endl;
        }
    }
    cout << ans;
}