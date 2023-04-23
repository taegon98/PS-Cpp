#include <iostream>
#include <vector>
using namespace std;
struct element {
	int y, x, num;
};
int N, M, ret = 987654321;
bool flag = true;
char arr[10][10], visited[10][10];
int dy[4] = { -1,0,1,0 }, dx[4] = { 0,1,0,-1 };
element e;
vector<element> v;

int get_max() {
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) if (arr[i][j] == '0') cnt++;
	}
	return cnt;
}

void go(int idx) {
	if (idx == v.size()) {
		ret = min(ret, get_max());
		return;
	}
	for (int i = idx; i < v.size(); i++) {
		int ny = v[i].y;
		int nx = v[i].x;
		vector<pair<int, int>> tmp;
		if (v[i].num == '1') {
			for (int j = 0; j < 4; j++) {
				ny = v[i].y; nx = v[i].x;
				while (1) {
					ny += dy[j]; nx += dx[j];
					if (ny < 0 or nx < 0 or ny >= N or nx >= M or arr[ny][nx] == '6') break;
					if (arr[ny][nx] == '0' and !visited[ny][nx]) {
						arr[ny][nx] = '#';
						tmp.push_back({ ny,nx });
					}
					visited[ny][nx] = 1;
 				}
				go(i + 1);
				ny = v[i].y; nx = v[i].x;
				while (!tmp.empty()) {
					ny = tmp.back().first; nx = tmp.back().second; tmp.pop_back();
					arr[ny][nx] = '0';
					visited[ny][nx] = 0;
				}
			}
		}
		else if (v[i].num == '2') {
			for (int j = 0; j < 2; j++) {
				for (int k = 0; k < 3; k += 2) {
					int nj = (j + k) % 4;
					ny = v[i].y; nx = v[i].x;
					while (1) {
						ny += dy[nj]; nx += dx[nj];
						if (ny < 0 or nx < 0 or ny >= N or nx >= M or arr[ny][nx] == '6') break;
						if (arr[ny][nx] == '0' and !visited[ny][nx]) {
							arr[ny][nx] = '#';
							tmp.push_back({ ny,nx });
						}
						visited[ny][nx] = 1;
					}
				}
				go(i + 1);
				ny = v[i].y; nx = v[i].x;
				while (!tmp.empty()) {
					ny = tmp.back().first; nx = tmp.back().second; tmp.pop_back();
					arr[ny][nx] = '0';
					visited[ny][nx] = 0;
				}
			}
		}
		else if (v[i].num == '3') {
			for (int j = 0; j < 4; j++) {
				for (int k = 0; k < 2; k++) {
					int nj = (j + k) % 4;
					ny = v[i].y; nx = v[i].x;
					while (1) {
						ny += dy[nj]; nx += dx[nj];
						if (ny < 0 or nx < 0 or ny >= N or nx >= M or arr[ny][nx] == '6') break;
						if (arr[ny][nx] == '0' and !visited[ny][nx]) {
							arr[ny][nx] = '#';
							tmp.push_back({ ny,nx });
						}
						visited[ny][nx] = 1;
					}
				}
				go(i + 1);
				ny = v[i].y; nx = v[i].x;
				while (!tmp.empty()) {
					ny = tmp.back().first; nx = tmp.back().second; tmp.pop_back();
					arr[ny][nx] = '0';
					visited[ny][nx] = 0;
				}
			}
		}
		else if (v[i].num == '4') {
			for (int j = 0; j < 4; j++) {
				for (int k = 0; k < 3; k++) {
					int nj = (j + k) % 4;
					ny = v[i].y; nx = v[i].x;
					while (1) {
						ny += dy[nj]; nx += dx[nj];
						if (ny < 0 or nx < 0 or ny >= N or nx >= M or arr[ny][nx] == '6') break;
						if (arr[ny][nx] == '0' and !visited[ny][nx]) {
							arr[ny][nx] = '#';
							tmp.push_back({ ny,nx });
						}
						visited[ny][nx] = 1;
					}
				}
				go(i + 1);
				ny = v[i].y; nx = v[i].x;
				while (!tmp.empty()) {
					ny = tmp.back().first; nx = tmp.back().second; tmp.pop_back();
					arr[ny][nx] = '0';
					visited[ny][nx] = 0;
				}
			}
		}
		else if (v[i].num == '5' and true) {
			for (int j = 0; j < 4; j++) {
				ny = v[i].y; nx = v[i].x;
				while (1) {
					ny += dy[j]; nx += dx[j];
					if (ny < 0 or nx < 0 or ny >= N or nx >= M or arr[ny][nx] == '6') break;
					if (arr[ny][nx] == '0') arr[ny][nx] = '#';
				}
			}
			go(i + 1);
			flag = false;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
			if (arr[i][j] != '0' and arr[i][j] != '6') {
				e.y = i; e.x = j; e.num = arr[i][j];
				v.push_back(e);
			}
		}
	}
	go(0);
	cout << ret;
}