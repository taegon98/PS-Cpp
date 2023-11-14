#include <iostream>
#include <deque>
using namespace std;
int n, W, L, temp, cur_w, cur_n, ret;
deque<int> q;
deque<pair<int, int>> temp_q;

void check() {
	for (int i = 0; i < temp_q.size(); i++) {
		temp_q[i].second++;
	}
	while (temp_q.size()) {
		if (temp_q.front().second > W) {
			cur_n--;
			cur_w -= temp_q.front().first;
			temp_q.pop_front();
		}
		else return;
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> W >> L;

	for (int i = 0; i < n; i++) {
		cin >> temp;
		q.push_back(temp);
	}

	while (q.size()) {
		ret++;
		check();
		if (cur_w + q.front() <= L and cur_n < W) {
			cur_w += q.front();
			temp_q.push_back({ q.front(), 1});
			q.pop_front();
			cur_n++;
		}
	}
	int extra = 0;
	if (temp_q.size()) {
		extra = W - temp_q.back().second + 1;
	}
	cout << ret + extra;
}