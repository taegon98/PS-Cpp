#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;
int N, M, K, r, c, s, ret = 987654321, dir = 1;
int arr[54][54], visited[6];
int dy[4] = { -1,0,1,0 }, dx[4] = { 0,1,0,-1 };
typedef struct Element {
	int y1, x1, y2, x2;
} element;
element e;
vector<element> v;

void rotate(vector<element> perm) {
	int temp[54][54];
	memcpy(temp, arr, sizeof(arr));
	int sy, sx, ey, ex, ny, nx, cur_y, cur_x, prev, preprev, cnt = 0;
	for (int i = 0; i < perm.size(); i++) {
		sy = perm[i].y1; sx = perm[i].x1;
		ey = perm[i].y2; ex = perm[i].x2;
		cur_y = sy; cur_x = sx;
		preprev = temp[cur_y][cur_x];
		while (1) {
			if (sy == ey && sx == ex) break;
			ny = cur_y + dy[dir];
			nx = cur_x + dx[dir];
			if (ny < sy || nx < sx || ny > ey || nx > ex) {
				dir = (dir + 1) % 4;
				cnt++;
				if (cnt == 4) {
					sy++; sx++;
					ey--; ex--;
					cur_y = sy; cur_x = sx;
					preprev = temp[cur_y][cur_x];
					cnt = 0;
				}
				continue;
			}
			prev = temp[ny][nx];
			temp[ny][nx] = preprev;
			preprev = prev;
			cur_y = ny; cur_x = nx;
		}
	}
	for (int i = 1; i <= N; i++) {
		int tmp_max = 0;
		for (int j = 1; j <= M; j++) {
			tmp_max += temp[i][j];
		}
		ret = min(ret, tmp_max);
	}
}

void go(int depth, vector<element> vv) {
	if (depth == K) {
		rotate(vv);
		return;
	}
	for (int i = 0; i < v.size(); i++) {
		if (visited[i]) continue;
		vv.push_back(v[i]);
		visited[i] = 1;
		go(depth + 1, vv);
		vv.pop_back();
		visited[i] = 0;
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N >> M >> K;
	vector<element> vv;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) cin >> arr[i][j];
	}
	for (int i = 1; i <= K; i++) {
		cin >> r >> c >> s;
		e.y1 = r - s; e.x1 = c - s;
		e.y2 = r + s; e.x2 = c + s;
		v.push_back(e);
	}
	go(0, vv);
	cout << ret;
}