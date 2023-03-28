#include <iostream>
using namespace std;

int N, L, ret;
int graph[104][104];
int visited1[104][104] = { 0 };
int visited2[104][104] = { 0 };

int check_row(int r) {
	int start = graph[r][0];
	for (int i = 1; i < N; i++) {
		if (graph[r][i] == start) continue;
		if (graph[r][i] > start) {
			start = graph[r][i];
			for (int j = 1; j <= L; j++) {
				int idx = i - j;
				if (visited1[r][idx]) return 0;
				if (idx < 0) return 0;
				if (start - graph[r][idx] != 1) return 0;
				visited1[r][idx] = 1;
			}
		}
		else if (graph[r][i] < start) {
			for (int j = 0; j < L; j++) {
				if (visited1[r][i]) return 0;
				if (i >= N) return 0;
				if (start - graph[r][i] != 1) return 0;
				visited1[r][i++] = 1;
			}
			i--;
			start = graph[r][i];
		}
	}
	return 1;
}

int check_col(int c) {
	int start = graph[0][c];
	for (int i = 1; i < N; i++) {
		if (graph[i][c] == start) continue;
		if (graph[i][c] > start) {
			start = graph[i][c];
			for (int j = 1; j <= L; j++) {
				int idx = i - j;
				if (visited2[idx][c]) return 0;
				if (idx < 0) return 0;
				if (start - graph[idx][c] != 1) return 0;
				visited2[idx][c] = 1;
			}
		}
		else if (graph[i][c] < start) {
			for (int j = 0; j < L; j++) {
				if (visited2[i][c]) return 0;
				if (i >= N) return 0;
				if (start - graph[i][c] != 1) return 0;
				visited2[i++][c] = 1;
			}
			i--;
			start = graph[i][c];
		}
	}
	return 1;
}

int main() {
	cin >> N >> L;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			cin >> graph[i][j];
	}
	for (int i = 0; i < N; i++) {
		ret += check_row(i);
	}
	for (int i = 0; i < N; i++) {
		ret += check_col(i);
	}
	cout << ret;
}