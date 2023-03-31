#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <vector>
using namespace std;

bool cmp(pair<string, int>& a, pair<string, int>& b) {
	return a.first > b.first;
}
int main() {
	unordered_map<string, int> map;
	int n; cin >> n;
	string s, status;
	for (int i = 0; i < n; i++) {
		cin >> s >> status;
		if (status == "enter") map[s]++;
		else if (status == "leave") {
			auto iter = map.find(s);
			map.erase(iter);
		}
	}
	vector<pair<string, int>> v(map.begin(), map.end());
	sort(v.begin(), v.end(), cmp);
	for (pair<string, int> ret : v) cout << ret.first << "\n";
}