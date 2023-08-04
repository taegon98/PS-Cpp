#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N, L, H;
vector<pair<int, int>> v;

void go(int depth, int h, bool flag, int space) {
	if (depth == N) {
		if (flag) space += v[depth - 1].second;
		cout << space;
		exit(0);
	}

	for (int i = depth; i < N; i++) {
		if (v[i].second >= h and flag) {
			int s = abs(v[depth - 1].first - v[i].first) * v[depth - 1].second;
			go(i + 1, v[i].second, true, space + s);
		}
		else if (v[i].second > h and !flag) return;
		else if (v[i].second <= h) {
			int s = abs(v[depth - 1].first - v[i].first) * v[i].second;
			if (flag) s += v[depth - 1].second;
			go(i + 1, v[i].second, false, space + s);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> L >> H;
		v.push_back({ L,H });
	}
	sort(v.begin(), v.end());
	go(1, v[0].second, true, 0);
}