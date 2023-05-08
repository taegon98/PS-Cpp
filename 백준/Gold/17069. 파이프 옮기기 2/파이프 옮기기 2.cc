#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
ll N, matrix[34][34], ret[34][34][3];
vector<pair<int, int>> v;

bool check(int y, int x) {
	for (auto a : v) {
		if (y == a.first and x == a.second) return false;
	}
	return true;
}

void go(int y, int x) {
	for (int i = 1; i <= N; i++) {
		for (int j = 2; j <= N; j++) {
			int ny = i + 1, nx = j + 1;
			if (ret[i][j][0]) {
				if (nx >= 1 and nx <= N and check(i,nx)) ret[i][nx][0] += ret[i][j][0];
				if (nx >= 1 and nx <= N and ny >= 1 and ny <= N
					and check(ny,nx) and check(ny-1,nx) and check(ny,nx-1)) ret[ny][nx][2] += ret[i][j][0];
			}
			if (ret[i][j][1]) {
				if (ny >= 1 and ny <= N and check(ny,j)) ret[ny][j][1] += ret[i][j][1];
				if (nx >= 1 and nx <= N and ny >= 1 and ny <= N
					and check(ny, nx) and check(ny - 1, nx) and check(ny, nx - 1)) ret[ny][nx][2] += ret[i][j][1];
			}
			if (ret[i][j][2]) {
				if (nx >= 1 and nx <= N and check(i,nx)) ret[i][nx][0] += ret[i][j][2];
				if (ny >= 1 and ny <= N and check(ny,j)) ret[ny][j][1] += ret[i][j][2];
				if (nx >= 1 and nx <= N and ny >= 1 and ny <= N
					and check(ny, nx) and check(ny - 1, nx) and check(ny, nx - 1)) ret[ny][nx][2] += ret[i][j][2];

			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> matrix[i][j];
			if (matrix[i][j] == 1) v.push_back({ i,j });
		}
	}
	ret[1][2][0] = 1;
	go(1, 2);
	cout << ret[N][N][0] + ret[N][N][1] + ret[N][N][2];
}