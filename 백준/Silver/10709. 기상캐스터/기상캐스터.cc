#include <iostream>
using namespace std;

char location[104][104];
int graph[104][104];
int H, W;

int main() {
	cin >> H >> W;

	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) cin >> location[i][j];
	}

	for (int i = 0; i < H; i++) {
		bool flag = false;
		int cnt = 0;
		for (int j = 0; j < W; j++) {
			if (flag and location[i][j] != 'c') graph[i][j] = cnt++;
			else if (location[i][j] == 'c') {
				flag = true;
				graph[i][j] = 0;
				cnt = 1;
			}
			else graph[i][j] = -1;
		}
	}
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) cout << graph[i][j] <<" ";
		cout << "\n";
	}
	return 0;
}