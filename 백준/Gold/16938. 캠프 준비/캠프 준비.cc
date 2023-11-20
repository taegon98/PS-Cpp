#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N, L, R, X, ret, arr[16];
vector<int> v;

void go(int target, int depth, int idx) {

	if (depth == target) {
		int tot = 0;
		for (auto var : v) tot += var;

		if (tot >= L and tot <= R) {
			if (v.back() - v[0] >= X) ret++;
		}
		return;
	}

	for (int i = idx; i < N; i++) {
		v.push_back(arr[i]);
		go(target, depth + 1, i + 1);
		v.pop_back();
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> N >> L >> R >> X;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + N);
	for (int i = 2; i <= N; i++) {
		v.clear();
		go(i, 0, 0);
	}
	cout << ret;
}