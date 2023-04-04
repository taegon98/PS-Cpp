#include <iostream>
#include <deque>
using namespace std;
int T, n;
string p, tmp;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		cin >> p >> n >> tmp;
		bool flag = true, ok = true;
		int pos = 1;
		deque<int> dq;

		while (1) {
			if (pos == tmp.size() - 1) break;
			int t = 0;
			bool ok = true;
			while (isdigit(tmp[pos])) {
				t = (t * 10) + (tmp[pos] - '0');
				pos++;
				ok = false;
			}
			if (!ok) dq.push_back(t);
			if (ok) pos++;
		}
		for (int i = 0; i < p.size(); i++) {
			if (p[i] == 'R') {
				if (flag) flag = false;
				else flag = true;
			}
			else if (p[i] == 'D' and !dq.size()) {
				cout << "error\n"; ok = false;
				break;
			}
			else if (flag and p[i] == 'D') dq.pop_front();
			else if (!flag and p[i] == 'D') dq.pop_back();
		}
		if (ok and dq.empty()) cout << "[]\n";
		else if (ok) {
			int i;
			cout << "[";
			if (flag) for (i = 0; i < dq.size() - 1; i++) cout << dq[i] << ",";
			else for (i = dq.size() - 1; i > 0; i--) cout << dq[i] << ",";
			cout << dq[i] << "]\n";
		}
	}
}