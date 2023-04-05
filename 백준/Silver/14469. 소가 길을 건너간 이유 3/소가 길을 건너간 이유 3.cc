#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N, a, b, t = 0;
vector<pair<int, int>> v;
bool cmp(pair<int, int>& a, pair<int, int>& b) {
	return a.first < b.first;
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> a >> b; v.push_back({ a,b });
	}
	sort(v.begin(), v.end(), cmp);
	t = v[0].first;
	for (int i = 0; i < N - 1; i++) {
		int tmp = t + v[i].second;
		if (tmp > v[i + 1].first) t = tmp;
		else t = v[i + 1].first;
	}
	cout << t + v[N - 1].second;
}