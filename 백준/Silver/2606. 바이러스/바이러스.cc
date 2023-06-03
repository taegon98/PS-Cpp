#include <iostream>
#include <vector>
using namespace std;
int n, m, c1, c2, ret, visited[101];
vector<int> v[101];

void go(int num) {
	for (auto var : v[num]) {
		if (!visited[var]) {
			visited[var] = 1;
			go(var);
			ret++;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> c1 >> c2;
		v[c1].push_back(c2);
		v[c2].push_back(c1);
	}
	visited[1] = 1;
	go(1);
	cout << ret;
}