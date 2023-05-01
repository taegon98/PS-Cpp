#include <iostream>
#include <unordered_map>
#include <algorithm>
using namespace std;
typedef long long ll;
ll A, B, tmp, ret;
unordered_map<ll, ll> mp;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> A >> B;
	for (int i = 0; i < A; i++) {
		cin >> tmp;
		mp[tmp]++;
	}
	for (int i = 0; i < B; i++) {
		cin >> tmp;
		mp[tmp]++;
	}
	
	for (auto num : mp) {
		if (num.second == 1) ret++;
	}
	cout << ret;
}