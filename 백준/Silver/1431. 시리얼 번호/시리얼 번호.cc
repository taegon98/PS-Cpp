#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N;
string str;
vector<string> v;

int check(string s) {
	int tot = 0;
	for (auto a : s) {
		if (a - '0' >= 0 and a - '0' <= 9) {
			tot += (a - '0');
		}
	}
	return tot;
}

bool cmp(string a, string b) {
	int temp_a = check(a);
	int temp_b = check(b);
	
	if (a.size() == b.size()) {
		if (temp_a == temp_b) {
			return a < b;
		}
		return temp_a < temp_b;
	}
	return a.size() < b.size();
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> str;
		v.push_back(str);
	}
	sort(v.begin(), v.end(), cmp);
	for (auto var : v) {
		cout << var << "\n";
	}
}