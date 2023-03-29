#include <iostream>
using namespace std;

int N, L, ret;
int graph[104][104], graph2[104][104];

int check_row(int arr[][104], int r) {
	int visited[104][104] = { 0 };
	int start = arr[r][0];
	for (int i = 1; i < N; i++) {
		if (arr[r][i] == start) continue;
		if (arr[r][i] > start) {
			start = arr[r][i];
			for (int j = 1; j <= L; j++) {
				int idx = i - j;
				if (visited[r][idx]) return 0;
				if (idx < 0) return 0;
				if (start - arr[r][idx] != 1) return 0;
				visited[r][idx] = 1;
			}
		}
		else if (arr[r][i] < start) {
			for (int j = 0; j < L; j++) {
				if (visited[r][i]) return 0;
				if (i >= N) return 0;
				if (start - arr[r][i] != 1) return 0;
				visited[r][i++] = 1;
			}
			i--;
			start = arr[r][i];
		}
	}
	return 1;
}

int main() {
	cin >> N >> L;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> graph[i][j];
			graph2[j][i] = graph[i][j];
		}
	}
	for (int i = 0; i < N; i++) {
		ret += check_row(graph, i);
		ret += check_row(graph2, i);
	}
	cout << ret;
}