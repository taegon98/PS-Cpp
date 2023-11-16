#include <iostream>
using namespace std;
int C, arr[12][12], ret, visited[12];

void go(int r, int ability) {

	if (r > 11) {
		ret = max(ret, ability);
		return;
	}

	for (int i = 1; i <= 11; i++) {
		if (!arr[r][i]) continue;
		if (visited[i]) continue;
		visited[i] = 1;
		go(r + 1, ability + arr[r][i]);
		visited[i] = 0;
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> C;
	
	for (int i = 0; i < C; i++) {
		ret = -987654321;
		for (int i = 1; i <= 11; i++) {
			for (int j = 1; j <= 11; j++) {
				cin >> arr[i][j];
			}
		}
		go(1, 0);
		cout << ret << "\n";
	}
}