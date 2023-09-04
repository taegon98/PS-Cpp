#include <iostream>
#include <vector>
using namespace std;
int N, K, s, ret;
vector<pair<int, int>> v(201);

void go1() {
	auto pre = v[0];
	for (int i = 1; i < s; i++) {
		auto temp = v[i];
		v[i] = pre;
		pre = temp;
	}
	v[0] = pre;
	v[s / 2 - 1].first = 0;
	return;
}

void go2() {
	for (int i = s / 2 - 2; i >= 0; i--) {
		if (v[i].first == 0) continue;
		if (v[i + 1].second != 0 and v[i + 1].first == 0) {
			v[i + 1].second--;
			v[i + 1].first = 1;
			v[i].first = 0;
		}
	}
	v[s / 2 - 1].first = 0;
	return;
}

void go3() {
	if (v[0].second != 0) {
		v[0].first = 1;
		v[0].second--;
	}
	return;
}

bool go4() {
	int cnt = 0;
	for (int i = 0; i < s; i++) {
		if (v[i].second == 0) cnt++;
		if (cnt == K) return false;
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N >> K;
	for (int i = 0; i < N * 2; i++) {
		v[i].first = 0;
		cin >> v[i].second;
		s++;
	}

	while (1) {
		ret++;
		go1();
		go2();
		go3();
		if (!go4()) {
			cout << ret;
			break;
		}
	}
	return 0;
}