#include <iostream>
using namespace std;

int go(int y, int x, int arr[16][16], int M) {
	int tot = 0;
	for (int i = y; i < y + M; i++) {
		for (int j = x; j < x + M; j++) {
			tot += arr[i][j];
		}
	}
	return tot;
}

int main() {
	int T, N, M;
	cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		cin >> N >> M;
		int ret = -987654321;
		int arr[16][16] = { 0 };

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> arr[i][j];
			}
		}

		for (int i = 0; i < N - M + 1; i++) {
			for (int j = 0; j < N - M + 1; j++) {
				ret = max(ret, go(i, j, arr, M));
			}
		}
		cout << "#" << tc << " " << ret << "\n";
	}
}