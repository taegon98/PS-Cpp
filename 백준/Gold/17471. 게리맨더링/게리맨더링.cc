#include <iostream>
#include <vector>
#include <cmath>
#include <string.h>
using namespace std;

int N, n, tmp, ret = 987654321;
int ppl[24];
vector<int> v[24];
vector<pair<int, int>> group[2];
bool visited[24] = { false };

void dfs(int pos, int g) {
	visited[pos] = true;
	for (int num : v[pos]) {
		bool ok = false;
		for (pair<int, int> t : group[g]) {
			if (t.first == num) {
				ok = true;
				break;
			}
		}
		if (ok and !visited[num])
			dfs(num, g);
	}
}

bool check(vector<pair<int, int>> tmp) {
	for (pair<int, int> num : tmp) {
		if (visited[num.first] == false) return false;
	}
	return true;
}

void cal() {
	int cost1 = 0, cost2 = 0;
	for (pair<int, int> num : group[0]) {
		cost1 += ppl[num.first];
	}
	for (pair<int, int> num : group[1]) {
		cost2 += ppl[num.first];
	}
	ret = min(ret, abs(cost1 - cost2));
}

void go(int n) {
	
	for (int i = 0; i < N; i++) {
		if (n & (1 << i)) group[1].push_back({ N - i, 1 });
		else group[0].push_back({ N - i, 0 });
	}
	memset(visited, false, sizeof(visited));
	dfs(group[0].front().first, 0);
	if (!check(group[0])) return;
	memset(visited, false, sizeof(visited));
	dfs(group[1].front().first, 1);
	if (!check(group[1])) return;

	cal();
}

int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> ppl[i];
	for (int i = 1; i <= N; i++) {
		cin >> n;
		for (int j = 0; j < n; j++) {
			cin >> tmp;  v[i].push_back(tmp);
		}
	}
	for (int i = 1; i < (1 << N) - 1; i++) {
		go(i);
		group[0].clear();
		group[1].clear();
	}
	if (ret == 987654321) cout << -1;
	else cout << ret;
}