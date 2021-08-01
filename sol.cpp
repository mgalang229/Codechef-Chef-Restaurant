#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tt;
	cin >> tt;
	while (tt--) {
		int n, m;
		cin >> n >> m;
		vector<pair<int, int>> a;
		for (int i = 0; i < n; i++) {
			int l, r;
			cin >> l >> r;
			// make pairs for every ['l', 'r') pair
			a.emplace_back(make_pair(l, r));
		}
		vector<int> p(m);
		for (int i = 0; i < m; i++) {
			cin >> p[i];
		}
		// sort the pairs in non-decreasing order based on the value of 'l' (start time)
		sort(a.begin(), a.end());
		for (int i = 0; i < m; i++) {
			int time = -1;
			// perform binary search (with modifications)
			// beginning index (first element)
			int start = 0;
			// last index (last element)
			int end = n - 1;
			while (start <= end) {
				// middle element (value to be compared)
				int mid = (start + end) / 2;
				if (a[mid].first == p[i]) {
					// if the arrival time is exactly the start time 
					// of an interval then, the time is 0
					time = 0;
					break;
				} else if (a[mid].first > p[i]) {
					// if the start time is greater than the arrival time, then
					// calculate the difference of the current start time and arrival time
					// before proceeding to the next middle element and store it to 'time'
					time = a[mid].first - p[i];
					// change the range of the search (1st half or left part)
					end = mid - 1;
				} else {
					// otherwise, calculate the interval of the start time up to the end time
					int range = (a[mid].second - a[mid].first);
					if (a[mid].first + range > p[i]) {
						// if the arrival time is within the interval, then the time is 0
						time = 0;
						break;
					} else if (a[mid].first + range == p[i]) {
						// if the arrival time is exactly equal to the end time, then the time is
						// the difference of the next start time and current arrival time
						if (mid < n - 1) {
							time = a[mid + 1].first - p[i];
						}
						break;
					} else {
						// change the range of the search (2nd half or right part)
						start = mid + 1;
					}
				}
			}
			// output the time
			cout << time << '\n';
		}
	}
	return 0;
}
