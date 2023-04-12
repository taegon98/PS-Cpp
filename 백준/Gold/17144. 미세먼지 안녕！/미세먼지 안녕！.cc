#include <iostream>
#include <vector>
using namespace std;
int R, C, T, x, y, nx, ny, weight, ret;
int arr[54][54];
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };
struct element {int r, c, w;};
element e;
vector<pair<int, int>> location;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> R >> C >> T;
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == -1) location.push_back({ i,j });
		}
	}

	for (int tc = 1; tc <= T; tc++) {
		vector<element> v;
		int tmp[54][54] = { 0 };
		for (int i = 1; i <= R; i++) {
			for (int j = 1; j <= C; j++) {
				e.r = i; e.c = j; e.w = arr[i][j];
				if (arr[i][j] > 0) v.push_back(e);
			}
		}
		for (int i = 0; i < v.size(); i++) {
			y = v[i].r; x = v[i].c; weight = v[i].w;
			int cnt = 0;
			for (int d = 0; d < 4; d++) {
				int ny = y + dy[d];
				int nx = x + dx[d];
				if (ny >= 1 and ny <= R and nx >= 1 and nx <= C and arr[ny][nx] != -1) {
					tmp[ny][nx] += (weight / 5); cnt++;
				}
			}
			arr[y][x] = weight - (weight / 5) * cnt;
		}
		for (int i = 1; i <= R; i++) {
			for (int j = 1; j <= C; j++) arr[i][j] += tmp[i][j];
		}
		int Row1 = location[0].first;
		int Col1 = location[0].second;
		int Row2 = location[1].first;
		int Col2 = location[1].second;

		for (int i = Row1 - 1; i >= 1; i--) {
			if (arr[i + 1][1] == -1) arr[i][1] = 0;
			else arr[i + 1][1] = arr[i][1];
		}
		for (int i = 1; i < C; i++) arr[1][i] = arr[1][i + 1];
		for (int i = 2; i <= Row1; i++) arr[i - 1][C] = arr[i][C];
		for (int i = C - 1; i > 1; i--) arr[Row1][i + 1] = arr[Row1][i];

		for (int i = Row2 + 1; i <= R; i++) {
			if (arr[i - 1][1] == -1) arr[i][1] = 0;
			else arr[i - 1][1] = arr[i][1];
		}
		for (int i = 1; i < C; i++) arr[R][i] = arr[R][i + 1];
		for (int i = R - 1; i >= Row2; i--) arr[i + 1][C] = arr[i][C];
		for (int i = C - 1; i > 1; i--) arr[Row2][i + 1] = arr[Row2][i];
		arr[Row1][Col1 + 1] = 0; arr[Row2][Col2 + 1] = 0;
	}
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) if (arr[i][j] != -1) ret += arr[i][j];
	}
	cout << ret;
}