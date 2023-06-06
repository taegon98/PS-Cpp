#include <iostream>
#include <queue>
using namespace std;
int M, N, H, arr[101][101][101], visited[101][101][101], ret;
int dy[] = { -1,1,0,0,0,0 }, dx[] = { 0,0,-1,1,0,0 }, dz[] = { 0,0,0,0,1,-1 };
struct location {
	int x, y, z;
};
location l;
queue<location> q;

bool check() {
	for (int i = 1; i <= H; i++) {
		for (int j = 1; j <= N; j++) {
			for (int k = 1; k <= M; k++) {
				if (arr[i][j][k] == 0) return true;
			}
		}
	}
	return false;
}

void go() {
	queue<location> temp;
	
	while (q.size()) {
		location loca = q.front(); q.pop();
		visited[loca.z][loca.y][loca.x] = 1;

		for (int i = 0; i < 6; i++) {
			int nz = loca.z + dz[i];
			int ny = loca.y + dy[i];
			int nx = loca.x + dx[i];

			if (nx < 1 or nx > M or ny < 1 or ny > N or nz < 1 or nz > H) continue;
			if (arr[nz][ny][nx] == -1 or visited[nz][ny][nx]) continue;
			arr[nz][ny][nx] = 1;
			visited[nz][ny][nx] = 1;
			l.z = nz; l.y = ny; l.x = nx;
			temp.push(l);
		}
	}
	q = temp;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> M >> N >> H;
	for (int i = 1; i <= H; i++) {
		for (int j = 1; j <= N; j++) {
			for (int k = 1; k <= M; k++) {
				cin >> arr[i][j][k];
				if (arr[i][j][k] == 1) {
					l.z = i, l.y = j, l.x = k;
					q.push(l);
				}
			}
		}
	}
	while (check()) {
		if (!q.size()) {
			cout << -1; exit(0);
		}
		ret++;
		go();
	}
	cout << ret;
}