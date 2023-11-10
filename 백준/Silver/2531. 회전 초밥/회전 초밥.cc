#include <iostream>
#include <unordered_map>
using namespace std;
int N, d, k, c, arr[30001], ret;
unordered_map<int, int> mp;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N >> d >> k >> c;
	int l = 0, r = k - 1;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < k; i++) {
		mp[arr[i]]++;
	}
	ret = max(ret, (int)mp.size());

	for (int i = 0; i < N; i++) {
		bool flag = false;
		mp[arr[l]]--;
		if (!mp[arr[l]]) mp.erase(arr[l]);

		l = (l + 1) % N;
		r = (r + 1) % N;

		mp[arr[r]]++;

		if (mp.find(c) == mp.end()) {
			mp[c] = 1;
			flag = true;
		}
		ret = max(ret, (int)mp.size());
		if (flag) mp.erase(c);
	}
	cout << ret;
}