#include <iostream>
#include <vector>
#include <map>
using namespace std;
int R, C, N, t = 1;
char arr[201][201];
vector<pair<int, int>> v1;
map<pair<int, int>, int> mp;
int dy[] = { -1,1,0,0 }, dx[] = { 0,0,-1,1 };

void explode() {
	for (auto var : v1) {
		arr[var.first][var.second] = '.';
		for (int i = 0; i < 4; i++) {
			int y = var.first + dy[i];
			int x = var.second + dx[i];

			if (y < 0 or x < 0 or y >= R or x >= C) continue;
			arr[y][x] = '.';
			if (mp.find({ y,x }) != mp.end()) mp.erase({ y,x });
		}
	}
}

void install() {
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (arr[i][j] == '.') {
				arr[i][j] = 'O';
				mp[{i, j}]++;
			}
		}
	}
}

void print() {
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cout << arr[i][j];
		}
		cout << "\n";
	}

}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> R >> C >> N;

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 'O') v1.push_back({ i,j });
		}
	}

	for (int i = 0; i < N; i++) {
		if (t == 1) {
			t++;  continue;
		}
		else if (t % 2 == 0) {
			install();
		}
		else if (t % 2 == 1) {
			explode();
			v1.clear();
			for (auto var : mp) {
				v1.push_back({ var.first.first, var.first.second });
			}
			mp.clear();
		}
		t++;
	}
	print();
}