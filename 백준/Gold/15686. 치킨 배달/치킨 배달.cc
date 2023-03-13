#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int N, M, tmp, idx, tot, ans = 1000000000;
vector<pair<int, int>> chicken;
vector<pair<int, int>> house;
vector<pair<int, int>> ret;

void dist() {
	tot = 0;
	for (pair<int, int> there_h : house) {
		int d = 1000000000;
		for (pair<int, int> there_r : ret) {
			d = min(d, abs(there_h.first - there_r.first) + abs(there_h.second - there_r.second));
		}
		tot += d;
	}
}
void combi(int idx, int cnt) {
	if (cnt == M) {
		dist();
		ans = min(ans, tot);
		return;
	}

	for (int i = idx; i < chicken.size(); i++) {
		ret.push_back({ chicken[i].first, chicken[i].second });
		combi(i + 1, cnt + 1);
		ret.pop_back();
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> tmp;
			if (tmp == 1) house.push_back({ i,j });
			else if (tmp == 2) chicken.push_back({ i,j });
		}
	}

	combi(0, 0);
	cout << ans;

	return 0;
}