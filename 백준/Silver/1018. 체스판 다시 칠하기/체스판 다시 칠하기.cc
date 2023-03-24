#include <iostream>
using namespace std;

int N, M, ret1 = 987654321, ret2 = 987654321;
char graph[54][54];
char graph1[54][54];
char graph2[54][54];

int main() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> graph[i][j];
		}
	}

	for (int i = 1; i <= 51; i++) {
		for (int j = 1; j <= 51; j++) {
			if ((i % 2 == 1 and j % 2 == 1)
				or (i % 2 == 0 and j % 2 == 0)) {
				graph1[i][j] = 'W';
				graph2[i][j] = 'B';
			}
			else {
				graph1[i][j] = 'B';
				graph2[i][j] = 'W';
			}
		}
	}

	for (int i = 1; i <= N - 7; i++) {
		for (int j = 1; j <= M - 7; j++) {
			int cnt1 = 0, cnt2 = 0;
			for (int r = i; r < 8 + i; r++) {
				for (int c = j; c < 8 + j; c++) {
					if (graph[r][c] != graph1[r][c]) cnt1++;
					if (graph[r][c] != graph2[r][c]) cnt2++;
				}
			}
			ret1 = min(cnt1, ret1);
			ret2 = min(cnt2, ret2);
		}
	}
	cout << min(ret1, ret2);
	
}