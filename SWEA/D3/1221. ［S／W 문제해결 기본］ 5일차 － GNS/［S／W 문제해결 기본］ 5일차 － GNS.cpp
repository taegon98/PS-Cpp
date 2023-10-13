#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
map<string, int> mp;
int T, N;
string s;

bool cmp(string s1, string s2) {
	return mp[s1] < mp[s2];
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> T;
	
	mp["ZRO"] = 0; mp["ONE"] = 1;
	mp["TWO"] = 2; mp["THR"] = 3;
	mp["FOR"] = 4; mp["FIV"] = 5;
	mp["SIX"] = 6; mp["SVN"] = 7;
	mp["EGT"] = 8; mp["NIN"] = 9;

	for (int tc = 1; tc <= T; tc++) {
		cin >> s >> N;
		vector<string> v;
		for (int i = 0; i < N; i++) {
			cin >> s;
			v.push_back(s);
		}

		sort(v.begin(), v.end(), cmp);

		cout << "#" << tc << " ";
		for (auto var : v) cout << var << " ";
		cout << "\n";
	}
}