#include <iostream>
using namespace std;

int N, M, H, n1, n2, ret = 987654321;
int visited[34][14];

bool dfs() {
	for (int i = 1; i <= N; i++) {
		int pos = i;
		for (int j = 1; j <= H; j++) {
			if (visited[j][pos]) pos++;
			else if (visited[j][pos - 1]) pos--;
		}
		if (pos != i) return false;
	}
	return true;
}

void combi(int idx, int cnt) {
	if (cnt > 3 or cnt >= ret) return;
	if (dfs()) {
		ret = min(ret, cnt);
		return;
	}
	for (int i = idx; i <= H; i++) {
		for (int j = 1; j <= N; j++) {
			if (visited[i][j] or visited[i][j + 1] or visited[i][j - 1]) continue;
			visited[i][j] = 1;
			combi(i, cnt + 1);
			visited[i][j] = 0;
		}
	}

}

int main() {
	cin >> N >> M >> H;
	for (int i = 0; i < M; i++) {
		cin >> n1 >> n2;
		visited[n1][n2] = 1;
	}
	combi(1, 0);
	if (ret == 987654321) cout << -1;
	else cout << ret;
	return 0;
}