#include <iostream>
#include <vector>
using namespace std;
int R, C, M, location = -1, ret;
struct shark {
	int s, d, z;
};
struct new_shark {
	int r, c, s, d, z;
};
shark tmp;
new_shark s;
shark graph[104][104];

void relocate(vector<new_shark>& v) {
	for (new_shark s : v) {
		if (!graph[s.r][s.c].z) {
			graph[s.r][s.c].s = s.s;
			graph[s.r][s.c].d = s.d;
			graph[s.r][s.c].z = s.z;
		}
		else {
			if (graph[s.r][s.c].z < s.z) {
				graph[s.r][s.c].s = s.s;
				graph[s.r][s.c].d = s.d;
				graph[s.r][s.c].z = s.z;
			}
		}
	}
}

void go() {
	vector<new_shark> l;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (graph[i][j].z) {
				int tmp_s = graph[i][j].s;
				int tmp_d = graph[i][j].d;
				int ny = i, nx = j, pre;
				while (tmp_s) {
					if (tmp_d == 1) {
						pre = ny;
						ny -= tmp_s;
						if (ny < 0) {
							ny = 0;
							tmp_d = 2;
							tmp_s -= pre;
						}
						else break;
					}
					else if (tmp_d == 2) {
						pre = ny;
						ny += tmp_s;
						if (ny > R - 1) {
							ny = R - 1;
							tmp_d = 1;
							tmp_s -= (R - 1 - pre);
						}
						else break;
					}
					else if (tmp_d == 3) {
						pre = nx;
						nx += tmp_s;
						if (nx > C - 1) {
							nx = C - 1;
							tmp_d = 4;
							tmp_s -= (C - 1 - pre);
						}
						else break;
					}		
					else if (tmp_d == 4) {
						pre = nx;
						nx -= tmp_s;
						if (nx < 0) {
							nx = 0;
							tmp_d = 3;
							tmp_s -= pre;
						}
						else break;
					}
				}
				s.r = ny; s.c = nx;
				s.d = tmp_d; s.s = graph[i][j].s; s.z = graph[i][j].z;
				graph[i][j].z = 0; //기존 상어 위치 무시
				l.push_back(s);
			}
		}
	}
	relocate(l);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> R >> C >> M;
	int r, c, s, d, z;
	for (int i = 0; i < M; i++) {
		cin >> r >> c >>tmp.s >> tmp.d >> tmp.z;
		graph[r - 1][c - 1] = tmp;
	}
	while (1) {
		location++;
		if (location >= C) break;
		for (int row = 0; row < R; row++) {
			if (graph[row][location].z) {
				ret += graph[row][location].z;
				graph[row][location].z = 0;
				break;
			}
		}
		go();
	}
	cout << ret;
}