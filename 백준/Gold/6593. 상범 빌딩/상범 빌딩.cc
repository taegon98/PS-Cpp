#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
struct coord {
	int z, y, x;
};
coord temp;
int L, R, C, sz, sy, sx, az, ay, ax;
int dz[] = { 0,0,0,0,-1,1 }, dy[] = { -1,1,0,0,0,0 }, dx[] = { 0,0,-1,1,0,0 };
string str;

bool go(int l, int r, int c, int visited[31][31][31], char arr[31][31][31]) {
	queue<coord> q;
	temp.z = l; temp.y = r; temp.x = c;
	q.push(temp);
	visited[l][r][c] = 1;

	while (q.size()) {
		int z = q.front().z;
		int y = q.front().y;
		int x = q.front().x;
		q.pop();

		for (int i = 0; i < 6; i++) {
			int nz = z + dz[i];
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (nz == az and ny == ay and nx == ax) {
				cout << "Escaped in " << visited[z][y][x] << " minute(s).\n";
				return true;
			}

			if (nz < 0 or ny < 0 or nx < 0 or nz >= L or ny >= R or nx >= C or visited[nz][ny][nx]) continue;
			if (arr[nz][ny][nx] == '#') continue;
			visited[nz][ny][nx] = visited[z][y][x] + 1;
			temp.z = nz; temp.y = ny; temp.x = nx;
			q.push(temp);
		}
	}
	return false;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	while (1) {
		int visited[31][31][31] = { 0 };
		char arr[31][31][31];
		cin >> L >> R >> C;
		if (L == 0 and R == 0 and C == 0) exit(0);
		for (int i = 0; i < L; i++) {
			for (int j = 0; j < R; j++) {
				cin >> str;
				for (int k = 0; k < C; k++) {
					arr[i][j][k] = str[k];
					if (str[k] == 'S') {
						sz = i;
						sy = j;
						sx = k;
					}
					if (str[k] == 'E') {
						az = i;
						ay = j;
						ax = k;
					}
				}
			}
		}
		if (!go(sz, sy, sx, visited, arr)) cout << "Trapped!\n";
	}
}