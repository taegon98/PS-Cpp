#include <iostream>
#include <queue>
using namespace std;
int R, C, visited[251][251];
char arr[251][251];
int temp_o, temp_v, ret_o, ret_v;
int dy[] = { -1,1,0,0 };
int dx[] = { 0,0,-1,1 };

void go(int y, int x) {

	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 or nx < 0 or ny >= R or nx >= C) continue;
		if (visited[ny][nx] or arr[ny][nx] == '#') continue;

		visited[ny][nx] = 1;
		if (arr[ny][nx] == 'o') temp_o++;
		else if (arr[ny][nx] == 'v') temp_v++;
		go(ny, nx);
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> R >> C;


	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			temp_o = 0; temp_v = 0;
			if (!visited[i][j] and arr[i][j] != '#') {
				visited[i][j] = 1;
				if (arr[i][j] == 'o') temp_o++;
				else if (arr[i][j] == 'v') temp_v++;
				go(i, j);

				if (temp_o <= temp_v) ret_v += temp_v;
				else if (temp_o > temp_v) ret_o += temp_o;
			}
		}
	}
	cout << ret_o << " " << ret_v;
}