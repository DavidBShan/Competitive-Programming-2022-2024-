#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    int INFTY = 1e9 + 7;

    vector<vector<pair<int, int>>> flights_base(N + 1);

    for (int i = 0; i < M; ++i) {
        int c, r, d, s;
        cin >> c >> r >> d >> s;
        flights_base[c].push_back({r, d, s});
    }

    vector<int> layovers(N + 1);
    for (int i = 1; i <= N; ++i) {
        cin >> layovers[i];
    }

    layovers[1] = 0;

    vector<vector<pair<int, int>>> flights(N + 1);

    for (int c = 1; c <= N; ++c) {
        for (const auto& flight : flights_base[c]) {
            flights[c].push_back({flight.first - layovers[c], flight.second, flight.third});
        }
        sort(flights[c].rbegin(), flights[c].rend());
    }

    vector<int> time(N + 1, INFTY);
    time[1] = 0;
    vector<int> idx(N + 1, 0);

    queue<pair<int, int>> q;

    for (const auto& flight : flights[1]) {
        q.push(flight);
    }

    while (!q.empty()) {
        auto [r, d, s] = q.front();
        q.pop();

        time[d] = min(time[d], s);

        while (idx[d] < flights[d].size() && flights[d][idx[d]].first >= s) {
            q.push(flights[d][idx[d]]);
            idx[d]++;
        }
    }

    for (int i = 1; i <= N; ++i) {
        if (time[i] != INFTY) {
            cout << time[i] << endl;
        } else {
            cout << -1 << endl;
        }
    }

    return 0;
}
