#include <iostream>
#include <vector>
using namespace std;

int N, arr[24][24], ret = -987654321;
vector<int> v;

void move() {
	int tmp[24][24], tot = 0;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++) tmp[i][j] = arr[i][j];

	for (int num : v) {
		int visited[21][21] = { 0 };
		if (num == 0) {     //상
			for (int c = 1; c <= N; c++) {
				for (int r = 2; r <= N; r++) {
					if (tmp[r][c] == 0) continue;
					else {
						int r_tmp = r;
						while (r_tmp > 1) {
							if (tmp[r_tmp - 1][c]) {
								if (tmp[r_tmp - 1][c] != tmp[r_tmp][c] or visited[r_tmp - 1][c]) break;
								tmp[r_tmp - 1][c] = tmp[r_tmp][c] + tmp[r_tmp][c];
								visited[r_tmp - 1][c] = 1;
								tmp[r_tmp][c] = 0;
								break;
							}
							else {
								tmp[r_tmp - 1][c] = tmp[r_tmp][c];
								tmp[r_tmp][c] = 0;
								r_tmp--;
							}
						}
					}
				}
			}
		}
		else if (num == 1) {	//하
			for (int c = 1; c <= N; c++) {
				for (int r = N - 1; r >= 1; r--) {
					if (tmp[r][c] == 0) continue;
					else {
						int r_tmp = r;
						while (r_tmp < N) {
							if (tmp[r_tmp + 1][c]) {
								if (tmp[r_tmp + 1][c] != tmp[r_tmp][c] or visited[r_tmp + 1][c]) break;
								tmp[r_tmp + 1][c] = tmp[r_tmp][c] + tmp[r_tmp][c];
								visited[r_tmp + 1][c] = 1;
								tmp[r_tmp][c] = 0;
								break;
							}
							else {
								tmp[r_tmp + 1][c] = tmp[r_tmp][c];
								tmp[r_tmp][c] = 0;
								r_tmp++;
							}
						}
					}
				}
			}
		}
		else if (num == 2) {	//좌
			for (int r = 1; r <= N; r++) {
				for (int c = 2; c <= N; c++) {
					if (tmp[r][c] == 0) continue;
					else {
						int c_tmp = c;
						while (c_tmp > 1) {
							if (tmp[r][c_tmp - 1]) {
								if (tmp[r][c_tmp - 1] != tmp[r][c_tmp] or visited[r][c_tmp - 1]) break;
								tmp[r][c_tmp - 1] = tmp[r][c_tmp] + tmp[r][c_tmp];
								visited[r][c_tmp - 1] = 1;
								tmp[r][c_tmp] = 0;
								break;
							}
							else {
								tmp[r][c_tmp - 1] = tmp[r][c_tmp];
								tmp[r][c_tmp] = 0;
								c_tmp--;
							}
						}
					}
				}
			}
		}
		else if (num == 3) {	//우
			for (int r = 1; r <= N; r++) {
				for (int c = N - 1; c >= 1; c--) {
					if (tmp[r][c] == 0) continue;
					else {
						int c_tmp = c;
						while (c_tmp < N) {
							if (tmp[r][c_tmp + 1]) {
								if (tmp[r][c_tmp + 1] != tmp[r][c_tmp] or visited[r][c_tmp + 1]) break;
								tmp[r][c_tmp + 1] = tmp[r][c_tmp] + tmp[r][c_tmp];
								visited[r][c_tmp + 1] = 1;
								tmp[r][c_tmp] = 0;
								break;
							}
							else {
								tmp[r][c_tmp + 1] = tmp[r][c_tmp];
								tmp[r][c_tmp] = 0;
								c_tmp++;
							}
						}
					}
				}
			}
		}
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) ret = max(ret, tmp[i][j]);
	}
}


void go(int depth) {
	if (depth == 5) {
		move();
		return;
	}
	for (int d = 0; d < 4; d++) {
		v.push_back(d);
		go(depth + 1);
		v.pop_back();
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) cin >> arr[i][j];
	}
	go(0);
	cout << ret;
}