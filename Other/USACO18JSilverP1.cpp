#include <bits/stdc++.h>
using namespace std;

struct Event {
	int time;
	int cow_id;
	bool is_start;
};

bool operator<(const Event &a, const Event &b) { return a.time < b.time; }

int main() {
	int n;
	cin >> n;
	vector<Event> events;

	for (int i = 0; i < n; i++) {
		int l, r;
		cin >> l >> r;
		// each cow interval can be represented by a start and end event
		events.push_back({l, i, true});
		events.push_back({r, i, false});
	}

	sort(events.begin(), events.end());

	// how much time each cow spends alone
	vector<int> alone_time(n);

	// cows that are currently working during within [prev_time, curr_time]
	set<int> active;

	// time of the previous event
	int prev_time = 0;

	// how much time is covered by all the cows together
	int total_time = 0;

	for (const Event &e : events) {
		int curr_time = e.time;

		// 1. update total time covered by all the cows
		if (active.size() > 0) { total_time += curr_time - prev_time; }

		// 2. check to see if there's only one cow in [prev_time, curr_time]
		if (active.size() == 1) {
			alone_time[*active.begin()] += curr_time - prev_time;
		}

		// 3. process the event
		if (e.is_start) {
			active.insert(e.cow_id);
		} else {
			active.erase(e.cow_id);
		}

		// 4. update prev_time
		prev_time = curr_time;
	}

	int min_alone_time = *min_element(alone_time.begin(), alone_time.end());
	cout << total_time - min_alone_time << endl;
}
