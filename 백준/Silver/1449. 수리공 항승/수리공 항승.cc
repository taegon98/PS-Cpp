#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int N, L, pos, visited[2001], ret;
vector<int> v;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N >> L;
	for (int i = 0; i < N; i++) {
		cin >> pos;
		v.push_back(pos * 2);
	}
	sort(v.begin(), v.end());
	for (auto pos : v) {
		if (pos == 0 and visited[pos] and visited[pos + 1]) continue;
		else if (pos == 2000 and visited[pos - 1] and visited[pos]) continue;
		else if (visited[pos - 1] and visited[pos] and visited[pos + 1]) continue;
		pos--; ret++;
		for (int j = 0; j < L * 2 + 1; j++) {
			if (pos > 2000) break;
			visited[pos++] = 1;
		}
	}
	cout << ret;
}