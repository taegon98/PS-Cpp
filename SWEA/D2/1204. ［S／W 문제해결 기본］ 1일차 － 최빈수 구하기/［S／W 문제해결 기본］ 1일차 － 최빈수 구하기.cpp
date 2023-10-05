#include <iostream>
#include <map>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T, num;
	cin >> T;
	
	for (int tc = 1; tc <= T; tc++) {
		map<int, int> mp;
		cin >> num;
		int max_val = -987654321, ans = -987654321;

		for (int i = 0; i < 1000; i++) {
			cin >> num;
			mp[num]++;
		}


		for (auto var : mp) {
			if (max_val < var.second) {
				max_val = var.second;
				ans = var.first;
			}
			else if (max_val == var.second) {
				if (ans < var.first) ans = var.first;
			}
		}
		cout << "#" << tc << " " << ans << "\n";
	}
}