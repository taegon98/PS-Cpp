#include <iostream>
#include <vector>
using namespace std;
int N, d, w, ret;
vector<pair<int, int>> v;

void check() {
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		if (v[i].first <= 0) cnt++;
	}
	ret = max(ret, cnt);
}

void go(int cur) {

	if (cur >= N) {
		check();
		return;
	}
		
	for (int i = 0; i < N; i++) {
		if (i == cur) continue;
		if (v[i].first <= 0) continue;
		if (v[cur].first <= 0) go(cur + 1);
		else {
			v[cur].first -= v[i].second;
			v[i].first -= v[cur].second;
			go(cur + 1);
			v[cur].first += v[i].second;
			v[i].first += v[cur].second;
		}
	}
	check();
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> d >> w;
		v.push_back({ d,w });
	}
	go(0);
	cout << ret;
}