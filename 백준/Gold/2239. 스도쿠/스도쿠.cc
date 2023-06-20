#include <iostream>
#include <vector>
using namespace std;
string s;
int ret, arr[10][10], visited1[10][10], visited2[10][10];
vector<pair<int, int>> v;

bool check() {
	for (int i = 1; i <= 9; i++) {
		int visited[10] = { 0 };
		for (int j = 1; j <= 9; j++) {
			if (!arr[i][j]) continue;
			if (visited[arr[i][j]]) return false;
			visited[arr[i][j]] = 1;
		}
	}

	for (int i = 1; i <= 9; i++) {
		int visited[10] = { 0 };
		for (int j = 1; j <= 9; j++) {
			if (!arr[j][i]) continue;
			if (visited[arr[j][i]]) return false;
			visited[arr[j][i]] = 1;
		}
	}
	int row = 1, col = 1;
	for (int i = 1; i <= 9; i++) {
		int visited[10] = { 0 };
		if (i != 1 and i % 3 == 1) {
			row = 1; col += 3;
		}
		else if (i != 1) row += 3;
		for (int j = row; j < row + 3; j++) {
			for (int k = col; k < col + 3; k++) {
				if (!arr[j][k]) continue;
				if (visited[arr[j][k]]) return false;
				visited[arr[j][k]] = 1;
			}
		}
	}
	return true;
}

void print() {
	for (int i = 1; i <= 9; i++) {
		for (int j = 1; j <= 9; j++)
			cout << arr[i][j];
		cout << "\n";
	}
}

void go(int idx) {
	if (idx == ret) {
		print();
		exit(0);
	}
	for (int i = idx; i < v.size(); i++) {
		for (int j = 1; j <= 9; j++) {
			if (!visited1[v[i].first][j] and !visited2[v[i].second][j]) {
				arr[v[i].first][v[i].second] = j;
				visited1[v[i].first][j] = 1;
				visited2[v[i].second][j] = 1;
				if (check())
					go(i + 1);
				arr[v[i].first][v[i].second] = 0;
				visited1[v[i].first][j] = 0;
				visited2[v[i].second][j] = 0;
			}
			if (j == 9) return;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	for (int i = 1; i <= 9; i++) {
		cin >> s;
		for (int j = 0; j < 9; j++) {
			arr[i][j + 1] = s[j] - '0';
			if (!arr[i][j + 1]) {
				v.push_back({ i,j + 1 });
				ret++;
			}
			else {
				visited1[i][arr[i][j + 1]] = 1;
				visited2[j + 1][arr[i][j + 1]] = 1;
			}
		}
	}
	go(0);
}