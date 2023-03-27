#include <iostream>
using namespace std;

int N, ret = 987654321;
char ch;
char graph[24][24];
char tmp[24][24];

void check() {
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			if (tmp[i][j] == 'T') cnt++;
	}
	ret = min(ret, cnt);
}

void y_axis(int n) {
	for (int i = 0; i < N; i++) {
		if (tmp[n][i] == 'T') tmp[n][i] = 'H';
		else if (tmp[n][i] == 'H') tmp[n][i] = 'T';
	}
}

void x_axis(int n) {
	for (int i = 0; i < N; i++) {
		if (tmp[i][n] == 'T') tmp[i][n] = 'H';
		else if (tmp[i][n] == 'H') tmp[i][n] = 'T';
	}
}

void go(int y) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			tmp[i][j] = graph[i][j];
	}
	for (int i = 0; i < N; i++) if (y & (1 << i)) y_axis(i);
	
	for (int i = 0; i < N; i++) {
		int cnt_T = 0, cnt_H = 0;
		for (int j = 0; j < N; j++) {
			if (tmp[j][i] == 'T') cnt_T++;
			else if (tmp[j][i] == 'H') cnt_H++;
		}
		if (cnt_T > cnt_H) x_axis(i);
	}
	check();
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> ch; graph[i][j] = ch;
		}
	}
	for (int i = 0; i < (1 << N); i++) {
		go(i);
	}
	cout << ret;
}