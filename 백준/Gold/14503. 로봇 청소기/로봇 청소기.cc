#include <iostream>
using namespace std;
int N, M, dir, cur_y, cur_x, ret, arr[51][51], visited[51][51];
int dy[] = { -1,0,1,0 };
int dx[] = { 0,1,0,-1 };

int check() {
	int cnt = 0;

	for (int i = 0; i < 4; i++) {
		int ny = cur_y + dy[i];
		int nx = cur_x + dx[i];
		
		if (arr[ny][nx] == 0 and !visited[ny][nx]) cnt++;
	}	
	return cnt;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> N >> M;
	cin >> cur_y >> cur_x >> dir;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
		}
	}

	while (1) {
		if (!visited[cur_y][cur_x]) {
			visited[cur_y][cur_x] = 1;
			ret++;
		}

		if (!check()) {
			int temp_dir = (dir + 2) % 4;

			int ny = cur_y + dy[temp_dir];
			int nx = cur_x + dx[temp_dir];

			if (arr[ny][nx] == 0) {
				cur_y = ny;
				cur_x = nx;
			}
			else break;
		}
		else {
			dir -= 1;
			if (dir < 0) dir = 3;

			int ny = cur_y + dy[dir];
			int nx = cur_x + dx[dir];

			if (arr[ny][nx] == 0 and !visited[ny][nx]) {
				cur_y = ny;
				cur_x = nx;
			}
		}
	}
	cout << ret;
}