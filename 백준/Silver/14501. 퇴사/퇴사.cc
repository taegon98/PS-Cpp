#include <iostream>
#include <vector>
using namespace std;
int N, ret = -987654321;
pair<int, int> temp;
vector<pair<int, int>> v;

void go(int idx, int cost) {
	if (idx == N + 1) {
		ret = max(ret, cost);
		return;
	}
	for (int i = idx; i < v.size(); i++) {
		if (i + v[i].first <= N + 1)
			go(i + v[i].first, cost + v[i].second);
		else {
			ret = max(ret, cost);
			continue;
		}
	}
	return;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N;
	v.push_back({ 0,0 });
	for (int i = 1; i <= N; i++) {
		cin >> temp.first >> temp.second;
		v.push_back(temp);
	}
	for (int i = 1; i < v.size(); i++)
		go(i + v[i].first, v[i].second);
	if (ret == -987654321) cout << 0;
	else cout << ret;
}