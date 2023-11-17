#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int T, N;
vector<int> v1;
vector<char> v2;
vector<string> ret;

void split(string s) {
	v1.clear(); v2.clear();

	while (s.size()) {
		int pos = -987654321;

		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '+' or s[i] == '-') {
				pos = i;
				break;
			}
		}
		
		if (pos == -987654321) {
			v1.push_back(stoi(s));
			return;
		}

		v1.push_back(stoi(s.substr(0, pos)));
		v2.push_back(s[pos]);
		s = s.substr(pos + 1);
	}
}

int cal(string s) {
	int tot;
 	string str;

	for (auto var : s) {
		if (var != ' ') str.push_back(var);
	}

	split(str);
	tot = v1[0];

	for (int i = 0; i < v2.size(); i++) {
		if (v2[i] == '+') {
			tot += (v1[i + 1]);
		}
		else if (v2[i] == '-') {
			tot -= (v1[i + 1]);
		}
	}
	return tot;
}

void go(int depth, string s) {

	if (depth >= N) {
		if (!cal(s)) {
			ret.push_back(s);
		}
		return;
	}
	go(depth + 1,  s + "+" + to_string(depth + 1));
	go(depth + 1,  s + "-" + to_string(depth + 1));
	go(depth + 1,  s + " " + to_string(depth + 1));
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		cin >> N;

		go(1, "1");
		sort(ret.begin(), ret.end());
		for (auto var : ret) cout << var << "\n";
		cout << "\n";
		ret.clear();
	}
}