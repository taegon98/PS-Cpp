#include <iostream>
#include <deque>
#include <string.h>
using namespace std;
int N, M, T, tmp, ret;
struct element {
	int x, d, k;
};
element e[54];
deque<int> dq[54];
bool flag;
bool visited[54][54] = { false };

void condition1() {
	for (int i = 1; i <= N; i++) {
		tmp = dq[i].front();
		if (!tmp) continue;
		if (tmp == dq[i].at(1)) {
			visited[i][1] = true; visited[i][0] = true;
			flag = true;
		}
		if (tmp == dq[i].at(M - 1)) {
			visited[i][M - 1] = true; visited[i][0] = true;
			flag = true;
		}
	}
}

void condition2() {
	for (int i = 1; i <= N; i++) {
		tmp = dq[i].at(M - 1);
		if (!tmp) continue;
		if (tmp == dq[i].at(M - 2)) {
			visited[i][M - 2] = true; visited[i][M - 1] = true;
			flag = true;
		}
		if (tmp == dq[i].at(0)) {
			visited[i][0] = true; visited[i][M - 1] = true;
			flag = true;
		}
	}
}

void condition3() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j < M - 1; j++) {
			tmp = dq[i].at(j);
			if (!tmp) continue;
			if (tmp == dq[i].at(j - 1)) {
				visited[i][j - 1] = true; visited[i][j] = true;
				flag = true;
			}
			if (tmp == dq[i].at(j + 1)) {
				visited[i][j + 1] = true; visited[i][j] = true;
				flag = true;
			}
		}
	}
}

void condition4() {
	for (int i = 0; i < M; i++) {
		if (!dq[1].at(i)) continue;
		if (dq[1].at(i) == dq[2].at(i)) {
			visited[1][i] = true; visited[2][i] = true;
			flag = true;
		}
	}
}

void condition5() {
	for (int i = 0; i < M; i++) {
		if (!dq[N].at(i)) continue;
		if (dq[N].at(i) == dq[N - 1].at(i)) {
			visited[N][i] = true; visited[N - 1][i] = true;
			flag = true;
		}
	}
}

void condition6() {
	for (int i = 2; i < N; i++) {
		for (int j = 0; j < M; j++) {
			tmp = dq[i].at(j);
			if (!tmp) continue;
			if (tmp == dq[i - 1].at(j)) {
				visited[i - 1][j] = true; visited[i][j] = true;
				flag = true;
			}
			if (tmp == dq[i + 1].at(j)) {
				visited[i + 1][j] = true; visited[i][j] = true;
				flag = true;
			}
		}
	}
}

void get_sum() {
	for (int i = 1; i <= N; i++) {
		while (dq[i].size()) {
			ret += dq[i].front(); dq[i].pop_front();
		}
	}
}

void get_avg() {
	int cnt = 0;
	float avg, s = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < M; j++) {
			tmp = dq[i].at(j);
			if (tmp) {
				cnt++; s += tmp;
			}
		}
	}
	avg = s / cnt;
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < M; j++) {
			tmp = dq[i].at(j);
			if (tmp) {
				if (tmp < avg) dq[i].at(j) += 1;
				else if (tmp > avg) dq[i].at(j) -= 1;
			}
		}
	}
}

void go() {
	for (int tc = 1; tc <= T; tc++) {
		memset(visited, 0, sizeof(visited));
		flag = false;
		for (int i = e[tc].x; i <= N; i += e[tc].x) {
			for (int j = 0; j < e[tc].k; j++) {
				if (e[tc].d == 0) {
					dq[i].push_front(dq[i].back());
					dq[i].pop_back();
				}
				else if (e[tc].d == 1) {
					dq[i].push_back(dq[i].front());
					dq[i].pop_front();
				}
			}
		}
		condition1();
		condition2();
		condition3();
		condition4();
		condition5();
		condition6();		
		for (int i = 1; i <= N; i++) {
			for (int j = 0; j < M; j++) {
				if (visited[i][j]) dq[i].at(j) = 0;
			}
		}
		if (!flag) get_avg();
	}
	get_sum();
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N >> M >> T;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> tmp;  dq[i].push_back(tmp);
		}
	}
	for (int i = 1; i <= T; i++) cin >> e[i].x >> e[i].d >> e[i].k;
	go();
	cout << ret;
}