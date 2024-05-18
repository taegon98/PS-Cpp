#include <iostream>
#include <string.h>
using namespace std;

int T, N, K;
int arr[16][16];

int main() {
	
	cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		cin >> N >> K;
		int ret = 0;
		memset(arr, 0, sizeof(arr));

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> arr[i][j];
			}
		}
		
		for (int i = 0; i < N; i++) {
			int temp = 0;
			for (int j = 0; j < N; j++) {
				if (arr[i][j]) temp++;
				else temp = 0;
				
				if (temp == K) {
					if (j == N - 1 or (j != N - 1 and !arr[i][j + 1])) ret++;
					else {
						while (j < N - 1) {
							j++;
							if (!arr[i][j]) break;
						}
						temp = 0;
					}
				}
			}
		}

		for (int i = 0; i < N; i++) {
			int temp = 0;
			for (int j = 0; j < N; j++) {
				if (arr[j][i]) temp++;
				else temp = 0;

				if (temp == K) {
					if (j == N - 1 or (j != N - 1 and !arr[j + 1][i])) ret++;
					else {
						while (j < N - 1) {
							j++;
							if (!arr[j][i]) break;
						}
						temp = 0;
					}
				}
			}
		}
		cout << "#" << tc << " " << ret << "\n";
	}
}