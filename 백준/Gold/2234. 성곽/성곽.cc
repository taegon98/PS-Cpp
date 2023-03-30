#include <iostream>
#include <string.h>
using namespace std;
struct Element {
	bool n, s, w, e;
};
int N, M, tmp, ret1, ret2 = -987654321, ret3 = -987654321, num = 1;
Element element[54][54];
int visited[54][54], coloring[2504];
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

int dfs(int sy, int sx, int depth) {
	visited[sy][sx] = num;
	if (!element[sy][sx].n) {
		if (!visited[sy - 1][sx]) depth += dfs(sy - 1, sx, 1);
	}
	if (!element[sy][sx].s) {
		if (!visited[sy + 1][sx]) depth += dfs(sy + 1, sx, 1);
	}
	if (!element[sy][sx].w) {
		if (!visited[sy][sx - 1]) depth += dfs(sy, sx - 1, 1);
	}
	if (!element[sy][sx].e) {
		if (!visited[sy][sx + 1]) depth += dfs(sy, sx + 1, 1);
	}
	return depth;
}

int main() {
	cin >> N >> M;
	for (int i = 1; i <= M; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> tmp;
			if (tmp & (1 << 0)) element[i][j].w = true;
			if (tmp & (1 << 1)) element[i][j].n = true;
			if (tmp & (1 << 2)) element[i][j].e = true;
			if (tmp & (1 << 3)) element[i][j].s = true;
		}
	}
	for (int i = 1; i <= M; i++) {
		for (int j = 1; j <= N; j++) {
			if (!visited[i][j]) {
				coloring[num] = dfs(i, j, 1);
				ret2 = max(coloring[num++], ret2);
				ret1++;
			}
		}
	}

	for (int i = 1; i <= M; i++) {
		for (int j = 1; j <= N; j++) {
			if (j < N and visited[i][j] != visited[i][j + 1])
				ret3 = max(ret3, coloring[visited[i][j]] + coloring[visited[i][j + 1]]);
			if (i < M and visited[i][j] != visited[i + 1][j])
				ret3 = max(ret3, coloring[visited[i][j]] + coloring[visited[i + 1][j]]);
		}
	}
	cout << ret1 << "\n";
	cout << ret2 << "\n";
	cout << ret3 << "\n";
}