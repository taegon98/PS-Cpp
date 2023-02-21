#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#define MAX 104

using namespace std;

int graph[MAX][MAX];
bool visited[MAX][MAX];
int dr[4] = { -1,1,0,0 };
int dc[4] = { 0,0,-1,1 };
int N, tmp, max_val = 0, ret = 1;

void dfs(int r, int c, int h) {
	visited[r][c] = true;
	
	for (int d= 0;d<4;d++) {
		int nr = r + dr[d];
		int nc = c + dc[d];

		if (nr >= 0 and nr < N and nc >= 0 and nc < N) {
			if (!visited[nr][nc] and graph[nr][nc] > h) dfs(nr, nc, h);
		}
	}
}

int main() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> tmp;
			if (tmp > max_val) max_val = tmp;

			graph[i][j] = tmp;
		}
	}

	for (int i = 0; i <= max_val; i++) {
		for (int v = 0; v < MAX; v++) memset(visited[v], false, sizeof(bool) * MAX);
		int cnt = 0;
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < N; k++) {
				if (!visited[j][k] and graph[j][k] > i) {
					dfs(j, k, i); cnt++;
				}
			}
		}
		if (ret < cnt) ret = cnt;
	}
	cout << ret;
	return 0;
}
