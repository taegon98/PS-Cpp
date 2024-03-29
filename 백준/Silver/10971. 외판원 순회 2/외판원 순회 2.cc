#include <iostream>
using namespace std;
#define INF 987654321
int N, arr[14][14];

int go(int idx, int num, int cur) {
	int ret = INF;
	if (idx == N) {
		if (arr[cur][1] != 0) return arr[cur][1];
		else return INF;
	}
	for (int i = 0; i < N; i++) {
		if (num & (1 << i)) continue;
		if (arr[cur][i + 1] == 0) continue;
		ret = min(ret, go(idx + 1, num | (1 << i), i + 1) + arr[cur][i + 1]);
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++)
			cin >> arr[i][j];
	}
	cout << go(1, 1, 1);
}