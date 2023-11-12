#include <iostream>
#include <unordered_map>
using namespace std;
int N, K, arr[200001], ret = 1;
unordered_map<int, int> mp;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	int l = 0, r = 0;
	mp[arr[l]]++;

	while (1) {
		r++;
		if (r == N) break;

		mp[arr[r]]++;

		if (mp[arr[r]] <= K) {
			ret = max(ret, r - l + 1);
			continue;
		}
		else {
			while (1) {
				if (arr[l] == arr[r]) {
					mp[arr[l]]--;
					l++;
					break;
				}
				else mp[arr[l]]--, l++;
			}
		}
	}
	cout << ret;
}