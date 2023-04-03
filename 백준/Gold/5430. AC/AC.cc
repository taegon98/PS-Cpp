#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int T, n;
string p, tmp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		int pointer = 0, pos = 0, left = 0, right, size;;
		bool flag = true, print = true;
		vector<int> v;
		cin >> p >> n >> tmp;

		while (1) {
			if (pos == tmp.size() - 1) break;
			int t = 0;
			bool ok = true;
			while (isdigit(tmp[pos])) {
				t = (t * 10) + (tmp[pos] - '0');
				pos++;
				ok = false;
			}
			if (!ok) v.push_back(t);
			if (ok) pos++;
		}
		size = v.size();
		right = v.size() - 1;
		for (int i = 0; i < p.size(); i++) {
			if (p[i] == 'R') {
				if (flag) {
					pointer = right; flag = false;
				}
				else {
					pointer = left; flag = true;
				}
			}
			else if (p[i] == 'D' and left > right) {
				cout << "error\n"; print = false;
				break;
			}
			else if (p[i] == 'D' and flag) {
				pointer++; left++; size--;
			}
			else if (p[i] == 'D' and !flag) {
				pointer--; right--; size--;
			}
		}
		if (print and !size and left > right) cout << "[]\n";
		else if (print and !v.empty()) {
			int i = pointer;
			cout << "[";
			if (flag) {
				for (; i < right; i++) cout << v[i] << ",";
			}
			else {
				for (; i > left; i--) cout << v[i] << ",";
			}
			cout << v[i] << "]\n";
		}
	}
}