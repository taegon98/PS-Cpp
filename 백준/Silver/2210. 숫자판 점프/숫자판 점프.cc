#include <iostream>
#include <set>
using namespace std;
string arr[5][5];
int dy[] = { -1,1,0,0 }, dx[] = { 0,0,-1,1 };
set<string> st;

void go(int depth, int y, int x, string s) {

	if (depth == 5) {
		st.insert(s);
		return;
	}
	
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 or nx < 0 or ny >= 5 or nx >= 5) continue;
		go(depth + 1, ny, nx, s + arr[ny][nx]);
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			go(0, i, j, arr[i][j]);
		}
	}

	cout << st.size();
}