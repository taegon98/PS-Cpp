#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;
map<string, int> mp;
vector<pair<string, int>> v;
int N, M;
string str;

bool cmp(pair<string, int>& a, pair<string, int>& b) {
	if (a.second == b.second) {
		if (a.first.size() == b.first.size()) {
			return a < b;
		}
		else return a.first.size() > b.first.size();
	}
	else return a.second > b.second;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> str;
		if (str.size() < M) continue;
		mp[str]++;
	}
	for (auto var : mp) {
		v.push_back({ var.first, var.second });
	}
	sort(v.begin(), v.end(), cmp);
	for (auto var : v) cout << var.first << "\n";
}