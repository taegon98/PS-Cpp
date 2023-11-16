#include <iostream>
using namespace std;
int N, arr[130][130], b, w;

bool check(int y, int x, int s) {

	int color = arr[y][x];

	for (int i = y; i < y + s; i++) {
		for (int j = x; j < x + s; j++) {
			if (arr[i][j] != color) return false;
		}
	}
	if (color == 1) b++;
	else if (color == 0) w++;
	return true;
}

void go(int y, int x, int n) {
	if (!check(y, x, n)) {
		go(y, x, n / 2);
		go(y, x + n / 2, n / 2);
		go(y + n / 2, x, n / 2);
		go(y + n / 2, x + n / 2, n / 2);
	}
	return;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}
	go(0, 0, N);
	cout << w << "\n" << b;
}