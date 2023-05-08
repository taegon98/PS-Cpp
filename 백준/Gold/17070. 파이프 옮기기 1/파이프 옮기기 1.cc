#include <iostream>
#include <vector>
using namespace std;
int N, matrix[20][20], ret;
vector<pair<int, int>> v;

void go(int y1, int x1, int y2, int x2) {
	if (y1 < 1 or x1 < 1 or y2 < 1 or x2 < 1) return;
	if (y1 > N or x1 > N or y2 > N or x2 > N) return;
	if (y1 == y2 and x1 + 1 == x2) {
		for (auto a : v) {
			if (y2 == a.first and x2 == a.second) return;
		}
	}
	if (y1 + 1 == y2 and x1 == x2) {
		for (auto a : v) {
			if (y2 == a.first and x2 == a.second) return;
		}
	}
	if (y1 + 1 == y2 and x1 + 1 == x2) {
		for (auto a : v) {
			if ((y2 == a.first and x2 == a.second)
				or (y2 - 1 == a.first and x2 == a.second)
				or (y2 == a.first and x2 - 1 == a.second)) return;
		}
	}
	if (y2 == N and x2 == N) {
		ret++; return;
	}

	if (y1 == y2 and x1 + 1 == x2) {
		go(y1, x1 + 1, y2, x2 + 1);
		go(y1, x1 + 1, y2 + 1, x2 + 1);
	}
	else if (y1 + 1 == y2 and x1 == x2) {
		go(y1 + 1, x1, y2 + 1, x2);
		go(y1 + 1, x1, y2 + 1, x2 + 1);
	}
	else if (y1 + 1 == y2 and x1 + 1 == x2) {
		go(y1 + 1, x1 + 1, y2, x2 + 1);
		go(y1 + 1, x1 + 1, y2 + 1, x2);
		go(y1 + 1, x1 + 1, y2 + 1, x2 + 1);
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++) {
			cin >> matrix[i][j];
			if (matrix[i][j] == 1) v.push_back({ i,j });
		}
	go(1, 1, 1, 2);
	cout << ret;
}