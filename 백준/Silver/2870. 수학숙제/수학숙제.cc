#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<string> v;
string s, ret;

void to_int() {
	while (ret.size() > 1 and ret[0] == '0') ret.erase(ret.begin());
	v.push_back(ret);
	ret.clear();
}

bool cmp(string a, string b) {
	if (a.size() == b.size()) return a < b;
	return a.size() < b.size();
}

int main() {
	int N;
	cin >> N;


	for (int i = 0; i < N; i++) {
		cin >> s;

		for (int j = 0; j < s.size(); j++) {
			if (isdigit(s[j])) {
				ret += s[j];
			}
			else if (ret.size()) to_int();
		}
		if (ret.size()) to_int();
	}

	sort(v.begin(), v.end(), cmp);
	for (string iter : v) {
		cout << iter << "\n";
	}
	return 0; 
}