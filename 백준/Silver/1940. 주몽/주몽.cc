#include <iostream>

using namespace std;

int arr[15004];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, M, cnt = 0;

	cin >> N;
	cin >> M;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			if (arr[i] + arr[j] == M) cnt++;
		}
	}
	cout << cnt;
	return 0;
}