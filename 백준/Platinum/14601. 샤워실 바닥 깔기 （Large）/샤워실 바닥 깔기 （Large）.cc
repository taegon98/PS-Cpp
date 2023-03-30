#include <iostream>
#include <cmath>
using namespace std;

int K, x, y, length, num = 1;
int graph[140][140];

int check(int r, int c, int k) {
	for (int i = r; i <= r + pow(2, k) - 1;  i++) {
		for (int j = c; j <= c + pow(2, k) - 1; j++) {
			if (graph[i][j] != 0) {
				if (i < r + pow(2, k) / 2) {
					if (j < c + pow(2, k) / 2) return 2;
					else return 1;
				}
				else {
					if (j < c + pow(2, k) / 2) return 3;
					else return 4;
				}
			}
		}
	}
}

void coloring(int q, int s, int y, int x) {
	y--; x--;
	if (q == 1) {
		graph[y + s][x + s] = num;
		graph[y + s + 1][x + s] = num;
		graph[y + s + 1][x + s+ 1] = num;
	}
	else if (q == 2) {
		graph[y + s][x + s + 1] = num;
		graph[y + s + 1][x + s] = num;
		graph[y + s + 1][x + s + 1] = num;
	}
	else if (q == 3) {
		graph[y + s][x + s] = num;
		graph[y + s][x + s + 1] = num;
		graph[y + s + 1][x + s + 1] = num;
	}
	else if (q == 4) {
		graph[y + s][x + s] = num;
		graph[y + s][x + s + 1] = num;
		graph[y + s + 1][x + s] = num;
	}
	num++;
}

void go(int sy, int sx, int s) {
	if (s == 0) return;

	int n = check(sy, sx, s);
	int j = pow(2, s) / 2;
	coloring(n, j, sy, sx);
	
	go(sy, sx, s - 1);
	go(sy, sx + j, s - 1);
	go(sy + j, sx, s - 1);
	go(sy + j, sx + j, s - 1);
}

int main() {
	cin >> K >> x >> y;
	y = pow(2, K) - y + 1;
	graph[y][x] = -1;
	go(1, 1, K);

	for (int i = 1; i <= pow(2, K); i++) {
		for (int j = 1; j <= pow(2, K); j++) cout << graph[i][j] << " ";
		cout << "\n";
	}
}