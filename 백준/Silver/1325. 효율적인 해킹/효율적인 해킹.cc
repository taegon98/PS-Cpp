#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;
#define MAX 10004

int N, M, r, c, cnt, max_val;
vector<int> v;
vector<int> graph[MAX];
bool visited[MAX];

void dfs(int start) {
	for (int i : graph[start]) {
		if (!visited[i]) {
			visited[i] = true;
			cnt++; dfs(i);
		}
	}
	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;

	for (int i = 1; i <= M; i++) {
		cin >> c >> r;
		graph[r].push_back(c);
	}

	for (int i = 1; i <= N; i++) {
		memset(visited, false, sizeof(bool) * MAX);
		cnt = 1;
		visited[i] = true;
		dfs(i);
		if (cnt > max_val) {
			max_val = cnt;
			v.clear();
			v.push_back(i);
		}
		else if (cnt == max_val) {
			v.push_back(i);
		}
	}

	for (int i : v) cout << i << " ";
	return 0;
}