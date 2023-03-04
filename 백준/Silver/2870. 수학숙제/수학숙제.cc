#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<string> v;
vector<string> v2;

void to_int() {
	for (auto iter : v) {
		while (iter.size() > 1 and iter[0] == '0') iter.erase(iter.begin());
		v2.push_back(iter);
	}
}

bool cmp(string a, string b) {
	if (a.size() == b.size()) return a < b;
	return a.size() < b.size();
}

int main() {
	long long N;
	string s, ret;
	
	
	cin >> N;

	for (int i = 0; i < N; i++) {
		char prev = ' ';
		cin >> s;

		for (int j = 0; j < s.size(); j++) {
			if (isdigit(s[j])) {
				ret += s[j];
			}
			if (isdigit(prev) and isalpha(s[j])) {
				v.push_back(ret);
				ret.clear();
			}
			prev = s[j];
		}

		if (ret.size()) {
			v.push_back(ret);
			ret.clear();
		}
	}
	to_int();
	sort(v2.begin(), v2.end(), cmp);
	for (auto iter : v2) {
		cout << iter << "\n";
	}
	return 0; 
}