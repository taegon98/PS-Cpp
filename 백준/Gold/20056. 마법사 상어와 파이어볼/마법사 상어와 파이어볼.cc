#include <iostream>
#include <deque>
#include <vector>
using namespace std;

int N, M, K, r, c;
int dy[] = { -1,-1,0,1,1,1,0,-1 } , dx[] = { 0,1,1,1,0,-1,-1,-1 };

struct info {
	int m, s, d;
};
info temp;

struct element {
	deque<info> dq1, dq2;
};

element e[51][51];

void dq2_to_dq1() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (e[i][j].dq2.size()) e[i][j].dq1.swap(e[i][j].dq2);
		}
	}
}

void go1() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			while (e[i][j].dq1.size()) {
				temp = e[i][j].dq1.front();
				e[i][j].dq1.pop_front();

				int ny = i, nx = j;
				for (int k = 0; k < temp.s; k++) {
					ny += dy[temp.d];
					nx += dx[temp.d];
					if (ny < 0) ny = N - 1;
					if (nx < 0) nx = N - 1;
					if (ny >= N) ny = 0;
					if (nx >= N) nx = 0;
				}

				e[ny][nx].dq2.push_back(temp);
			}
		}
	}
}

void go2() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (e[i][j].dq2.size() >= 2) {
				int tot_m = 0, tot_s = 0, flag = 0, dir;
				bool ok = false;
				for (auto var : e[i][j].dq2) {
					if (flag != 0 and
						((flag == 1 and var.d % 2 == 0) or (flag == 2 and var.d % 2 == 1))) {
						ok = true;
					}
					if (var.d % 2 == 0) flag = 2;
					else flag = 1;
					tot_m += var.m;
					tot_s += var.s;
				}

				if (tot_m < 5) {
					e[i][j].dq2.clear();
					continue;
				}

				tot_s /= e[i][j].dq2.size();
				
				if (ok) dir = -1;
				else dir = -2;

				for (int K = 0; K < 4; K++) {
					info t;
					t.m = tot_m / 5; t.s = tot_s;
					dir += 2;
					t.d = dir;
					e[i][j].dq1.push_back(t);
				}
				e[i][j].dq2.clear();
			}
		}
	}
}

int get_answer() {
	int tot = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < e[i][j].dq1.size(); k++) {
				tot += e[i][j].dq1[k].m;
			}
		}
	}
	return tot;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N >> M >> K;
	for (int i = 0; i < M; i++) {
		cin >> r >> c >> temp.m >> temp.s >> temp.d;
		e[r - 1][c - 1].dq1.push_back(temp);
	}

	while (1) {
		if (!K) break;
		go1();
		go2();
		K--;
		dq2_to_dq1();
	}
	cout << get_answer();
}