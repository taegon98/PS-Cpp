#include <iostream>
#include <vector>
using namespace std;
int N, ret, arr[16][16];
pair<int, int> pos[16];

bool check(int y, int x) {
	for (int i = 0; i < y; i++) {
		if (arr[i][x]) return false;
		if (abs(y - pos[i].first) == abs(x - pos[i].second)) return false;
	}
	return true;
}

void go(int depth, int y) {
	if (depth == N) ret++;
	for (int x = 0; x < N; x++) {
		if (check(y, x)) {
			arr[y][x] = 1;
			pos[y] = { y,x };
			go(depth + 1, y + 1);
			arr[y][x] = 0;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N;
	go(0, 0);
	cout << ret;
}