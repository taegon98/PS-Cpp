#include <iostream>
#include <vector>
using namespace std;
vector<pair<int, int>> v;
int ret = -987654321;

void go(int idx, int tot_score, int tot_cal, int l) {
	
	if (tot_cal > l) {
		return;
	}
	ret = max(ret, tot_score);

	for (int i = idx; i < v.size(); i++) {
		go(i + 1, tot_score + v[i].first, tot_cal + v[i].second, l);
	}
}

int main() {
	int T, N, L;
	cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		cin >> N >> L;
		v.clear();
		ret = -987654321;

		int score, cal;

		for (int i = 0; i < N; i++) {
			cin >> score >> cal;
			v.push_back({ score, cal });
		}
		go(0, 0, 0, L);
		cout << "#" << tc << " " << ret << "\n";
	}
}