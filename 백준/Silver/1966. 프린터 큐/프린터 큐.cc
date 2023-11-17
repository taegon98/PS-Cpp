#include <iostream>
#include <queue>
using namespace std;
deque<pair<int, int>> q, tmp;
int T, N, target, temp, ret;

int check(int pri) {
	tmp.clear();
	int idx = 0, max_value = pri;
	for (int i = 1; i < q.size(); i++) {
		tmp.push_back(q[i - 1]);
		if (q[i].first > max_value) {
			idx = i;
			max_value = q[i].first;
		}
	}
	return idx;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		q.clear();
		ret = 1;
		cin >> N >> target;

		for (int i = 0; i < N; i++) {
			cin >> temp;
			q.push_back({ temp,i });
		}

		while (q.size()) {
			temp = q.front().first;
			int idx = check(temp);

			for (int j = 0; j < idx; j++) {
				q.pop_front();
				q.push_back(tmp[j]);
			}

			if (q.front().second == target) {
				cout << ret << "\n";
				break;
			}
			q.pop_front();

			ret++;
		}
	}
}