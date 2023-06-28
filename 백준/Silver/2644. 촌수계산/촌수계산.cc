#include <iostream>
#include <vector>
using namespace std;
int n, m, x, y, r1, r2;
int visited[101];
vector<int> v[101];

void go(int num, int depth) {
	if (num == r2) {
		cout << depth;
		exit(0);
	}
	for (auto var : v[num]) {
		if (visited[var]) continue;
		visited[var] = 1;
		go(var, depth + 1);
		visited[var] = 0;
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> r1 >> r2 >> m;
	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	go(r1, 0);
	cout << -1;
}