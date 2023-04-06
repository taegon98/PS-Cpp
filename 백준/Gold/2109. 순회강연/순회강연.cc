#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, p, d, ret;
vector<pair<int, int>> v;
bool visited[10004];

bool cmp(pair<int, int>& a, pair<int, int>& b) {
	return a.second > b.second;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> p >> d;
		v.push_back({ d,p });
	}
	sort(v.begin(), v.end(), cmp);
	for (pair<int, int> p : v) {
		int tmp = p.first;
		while (1) {
			if (!visited[tmp])break;
			if (tmp < 1)break;
			tmp--;
		}
		if (tmp > 0) {
			visited[tmp] = true;
			ret += p.second;
		}
	}
	cout << ret;
}