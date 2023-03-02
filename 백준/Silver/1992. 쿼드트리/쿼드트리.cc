#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#define MAX 68
using namespace std;

int N;
int graph[MAX][MAX];

void dfs(int y, int x, int size) {
	int p = graph[y][x];

	for (int r = 0; r < size; r++) {
		for (int c = 0; c < size; c++) {
			if (graph[y + r][x + c] != p) {
				cout << "(";
				dfs(y, x, size / 2);
				dfs(y, x + size / 2, size / 2);
				dfs(y + size / 2, x, size / 2);
				dfs(y + size / 2, x + size / 2, size / 2);
				cout << ")"; return;
			}
		}
	}
	cout << p;
}

int main() {
	
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%1d", &graph[i][j]);
		}
	}

	dfs(0, 0, N);

	return 0;
}