#include <iostream>
using namespace std;
int N;
int dy[] = { -1,1,0,0 }, dx[] = { 0,0,-1,1 };
char arr[51][51];
string str;
int max_val = -987654321;

void get_num() {
	
	for (int i = 0; i < N; i++) {
		int cnt = 1;
		char ch = arr[i][0];
		for (int j = 1; j < N; j++) {
			if (ch == arr[i][j]) cnt++;
			else {
				max_val = max(max_val, cnt);
				ch = arr[i][j];
				cnt = 1;
			}
		}
		max_val = max(max_val, cnt);
	}
	for (int i = 0; i < N; i++) {
		int cnt = 1;
		char ch = arr[0][i];
		for (int j = 1; j < N; j++) {
			if (ch == arr[j][i]) cnt++;
			else {
				max_val = max(max_val, cnt);
				ch = arr[j][i];
				cnt = 1;
			}
		}
		max_val = max(max_val, cnt);
	}
}

void go(int y, int x) {
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 or nx < 0 or ny >= N or nx >= N) continue;
		if (arr[y][x] == arr[ny][nx]) continue;
		swap(arr[y][x], arr[ny][nx]);
		get_num();
		swap(arr[y][x], arr[ny][nx]);
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> str;
		for (int j = 0; j < N; j++) {
			arr[i][j] = str[j];
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			go(i, j);
		}
	}
	cout << max_val;
}