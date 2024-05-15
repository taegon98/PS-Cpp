#include <iostream>
#include <string>
using namespace std;

int ret = -987654321;

void go(int depth, string s, int n) {

	if (n == depth) {
		ret = max(ret, stoi(s));
		return;
	}

	for (int i = 0; i < s.size() - 1; i++) {
		for (int j = i + 1; j < s.size(); j++) {
			swap(s[i], s[j]);
			go(depth + 1, s, n);
			swap(s[i], s[j]);
		}
		
	}
}

int main() {
	int t;

	cin >> t;

	for (int tc = 1; tc <= t; tc++) {
		ret = -987654321;
		string s;
		int n, b = 0;

		cin >> s >> n;

		if (n > s.size()) {
			n = s.size();
			b = n - s.size();
		}
		go(0, s, n);

		if (b) {
			for (int i = 0; i < b; i++) {
				swap(s[s.size() - 2], s[s.size() - 1]);
			}
			ret = stoi(s);
		}

		cout << "#" << tc << " " << ret << "\n";
	}
}