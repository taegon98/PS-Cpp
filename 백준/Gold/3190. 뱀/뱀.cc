#include <iostream>
#include <deque>
using namespace std;
int N, K, L, y, x, tmp, sy = 1, sx = 1, idx = 1, dir = 1;
int arr[104][104], order[10004] = { 0 }, visited[104][104] = { 0 };
char ch;
deque<pair<int, int>> dq;
int dy[4] = { -1,0,1,0 }, dx[4] = { 0,1,0,-1 };

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N >> K;
	for (int i = 1; i <= K; i++) {
		cin >> y >> x;
		arr[y][x] = -1;
	}
	cin >> L;
	for (int i = 1; i <= L; i++) {
		cin >> tmp >> ch;
		if (ch == 'D') order[tmp] = 1;
		else if (ch == 'L') order[tmp] = -1;
	}
	dq.push_back({ sy,sx });
	visited[sy][sx] = 1;
	while (1) {
		int ny = dq.back().first + dy[dir];
		int nx = dq.back().second + dx[dir];
		if (visited[ny][nx]) break;
		if (arr[ny][nx] != -1) {
			visited[dq.front().first][dq.front().second] = 0; dq.pop_front();
			dq.push_back({ ny,nx });
		}
		else if (arr[ny][nx] == -1) {
			dq.push_back({ ny,nx });
			arr[ny][nx] = 0;
		}
		visited[ny][nx] = 1;
		if (order[idx]) {
			if (dir == 0 and order[idx] == -1) dir = 3;
			else dir = (dir + order[idx]) % 4;
		}
		if (dq.back().first < 1 || dq.back().second < 1 || dq.back().first > N || dq.back().second > N) break;
		idx++;
	}
	cout << idx;
}