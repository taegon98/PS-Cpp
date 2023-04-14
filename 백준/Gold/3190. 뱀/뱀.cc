#include <iostream>
#include <deque>
using namespace std;
int N, K, L, y, x, tmp, sy = 1, sx = 1, idx = 1, dir = 4;
//상->1, 하->2, 좌->3, 우->4
int arr[104][104], order[10004] = { 0 }, visited[104][104] = { 0 };
char ch;
deque<pair<int, int>> dq;

void rotate() {
	if (order[idx] == 1) {
		if (dir == 4) dir = 2;
		else if (dir == 2) dir = 3;
		else if (dir == 3) dir = 1;
		else if (dir == 1) dir = 4;
	}
	else if (order[idx] == 2) {
		if (dir == 4) dir = 1;
		else if (dir == 2) dir = 4;
		else if (dir == 3) dir = 2;
		else if (dir == 1) dir = 3;
	}
}

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
		else if (ch == 'L') order[tmp] = 2;
	}
	dq.push_back({ sy,sx });
	visited[sy][sx] = 1;
	while (1) {
		if (dir == 1) {
			if (visited[sy - 1][sx]) break;
			if (arr[sy - 1][sx] != -1) {
				visited[dq.front().first][dq.front().second] = 0; dq.pop_front();
				dq.push_back({ sy - 1,sx });
			}
			else if (arr[sy - 1][sx] == -1) {
				dq.push_back({ sy - 1,sx });
				arr[sy - 1][sx] = 0;
			}
			visited[sy - 1][sx] = 1;
			sy--;
		}
		if (dir == 2) {
			if (visited[sy + 1][sx]) break;
			if (arr[sy + 1][sx] != -1) {
				visited[dq.front().first][dq.front().second] = 0; dq.pop_front();
				dq.push_back({ sy + 1,sx });
			}
			else if (arr[sy + 1][sx] == -1) {
				dq.push_back({ sy + 1,sx });
				arr[sy + 1][sx] = 0;
			}
			visited[sy + 1][sx] = 1;
			sy++;
		}
		if (dir == 3) {
			if (visited[sy][sx - 1]) break;
			if (arr[sy][sx - 1] != -1) {
				visited[dq.front().first][dq.front().second] = 0; dq.pop_front();
				dq.push_back({ sy,sx - 1 });
			}
			else if (arr[sy][sx - 1] == -1) {
				dq.push_back({ sy,sx - 1 });
				arr[sy][sx - 1] = 0;
			}
			visited[sy][sx - 1] = 1;
			sx--;
		}
		if (dir == 4) {
			if (visited[sy][sx + 1]) break;
			if (arr[sy][sx + 1] != -1) {
				visited[dq.front().first][dq.front().second] = 0; dq.pop_front();
				dq.push_back({ sy,sx + 1 });
			}
			else if (arr[sy][sx + 1] == -1) {
				dq.push_back({ sy,sx + 1 });
				arr[sy][sx + 1] = 0;
			}
			visited[sy][sx + 1] = 1;
			sx++;
		}
		if (order[idx]) rotate();
		if (dq.back().first < 1 || dq.back().second < 1 || dq.back().first > N || dq.back().second > N) break;
		idx++;
	}
	cout << idx;
}