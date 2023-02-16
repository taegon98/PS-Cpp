#include <iostream>
#include <map>
#include <string>

using namespace std;

map<string, int> mp;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int T, n;
	string s;

	cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		cin >> n;
		mp.clear();
		cin.ignore();

		int tot = 1;

		for (int i = 0; i < n; i++) {
			getline(cin, s);
			int pos = s.find(' ');

			string tmp = s.substr(pos + 1);
			mp[tmp]++;
		}

		for (auto iter : mp) {
			tot *= (iter.second + 1);
		}
		cout << tot - 1 << "\n";
	}
	
	return 0;
}