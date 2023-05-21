#include <iostream>
using namespace std;
#define INF 987654321
int arr[14][14], dp[14][14][6][6][6][6][6];

bool check(int y, int x, int n) {
	for (int i = y; i < y + n; i++) {
		for (int j = x; j < x + n; j++)
			if (arr[i][j] == 0 or i < 1 or j < 1 or i > 10 or j > 10) return false;
	}
	return true;
}

bool done() {
	for (int i = 1; i <= 10; i++)
		for (int j = 1; j <= 10; j++)
			if (arr[i][j]) return false;
	return true;
}

int go(int _1, int _2, int _3, int _4, int _5, int y, int x) {
    if (_1 > 5 or _2 > 5 or _3 > 5 or _4 > 5 or _5 > 5) return INF;
	if (done()) return 0;
	if (dp[y][x][_1][_2][_3][_4][_5]) return dp[y][x][_1][_2][_3][_4][_5];
	else dp[y][x][_1][_2][_3][_4][_5] = INF;

	for (int i = 1; i <= 10; i++) {
		for (int j = 1; j <= 10; j++) {
			if (arr[i][j]) {
				if (check(i, j, 1)) {
					int r, c;
					for (r = i; r < i + 1; r++) {
						for (c = j; c < j + 1; c++)
							arr[r][c] = 0;
					}
					dp[y][x][_1][_2][_3][_4][_5] = min(
						dp[y][x][_1][_2][_3][_4][_5], go(_1 + 1, _2, _3, _4, _5, r, c) + 1);
					for (r = i; r < i + 1; r++) {
						for (c = j; c < j + 1; c++)
							arr[r][c] = 1;
					}
				}
				else return dp[y][x][_1][_2][_3][_4][_5];
				if (check(i, j, 2)) {
					int r, c;
					for (r = i; r < i + 2; r++) {
						for (c = j; c < j + 2; c++)
							arr[r][c] = 0;
					}
					dp[y][x][_1][_2][_3][_4][_5] = min(
						dp[y][x][_1][_2][_3][_4][_5], go(_1, _2 + 1, _3, _4, _5, r, c) + 1);
					for (r = i; r < i + 2; r++) {
						for (c = j; c < j + 2; c++)
							arr[r][c] = 1;
					}
				}
				else return dp[y][x][_1][_2][_3][_4][_5];
				if (check(i, j, 3)) {
					int r, c;
					for (r = i; r < i + 3; r++) {
						for (c = j; c < j + 3; c++)
							arr[r][c] = 0;
					}
					dp[y][x][_1][_2][_3][_4][_5] = min(
						dp[y][x][_1][_2][_3][_4][_5], go(_1, _2, _3 + 1, _4, _5, r, c) + 1);
					for (r = i; r < i + 3; r++) {
						for (c = j; c < j + 3; c++)
							arr[r][c] = 1;
					}
				}
				else return dp[y][x][_1][_2][_3][_4][_5];
				if (check(i, j, 4)) {
					int r, c;
					for (r = i; r < i + 4; r++) {
						for (c = j; c < j + 4; c++)
							arr[r][c] = 0;
					}
					dp[y][x][_1][_2][_3][_4][_5] = min(
						dp[y][x][_1][_2][_3][_4][_5], go(_1, _2, _3, _4 + 1, _5, r, c) + 1);
					for (r = i; r < i + 4; r++) {
						for (c = j; c < j + 4; c++)
							arr[r][c] = 1;
					}
				}
				else return dp[y][x][_1][_2][_3][_4][_5];
				if (check(i, j, 5)) {
					int r, c;
					for (r = i; r < i + 5; r++) {
						for (c = j; c < j + 5; c++)
							arr[r][c] = 0;
					}
					dp[y][x][_1][_2][_3][_4][_5] = min(
						dp[y][x][_1][_2][_3][_4][_5], go(_1, _2, _3, _4, _5 + 1, r, c) + 1);
					for (r = i; r < i + 5; r++) {
						for (c = j; c < j + 5; c++)
							arr[r][c] = 1;
					}
				}
				else return dp[y][x][_1][_2][_3][_4][_5];
			}
		}
	}
	return dp[y][x][_1][_2][_3][_4][_5];
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	for (int i = 1; i <= 10; i++)
		for (int j = 1; j <= 10; j++)
			cin >> arr[i][j];
	int ret = go(0, 0, 0, 0, 0, 1, 1);
	if (ret == INF) cout << -1;
	else cout << ret;
}