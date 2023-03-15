#include <iostream>
#include <queue>
using namespace std;

int N;
struct Node {
	int a, b, c;
};
Node node;
int visited[64][64][64];
int arr[6][3] = {
	{9,3,1},
	{9,1,3},
	{3,9,1},
	{3,1,9},
	{1,9,3},
	{1,3,9}
};

void bfs(int x, int y, int z) {
	visited[x][y][z] = 1;
	queue<Node> q;
	q.push({ x,y,z });

	while (!q.empty()) {
		int a = q.front().a;
		int b = q.front().b;
		int c = q.front().c;
		q.pop();

		if (visited[0][0][0]) break;
		for (int d = 0; d < 6; d++) {
			int na = max(0, a - arr[d][0]);
			int nb = max(0, b - arr[d][1]);
			int nc = max(0, c - arr[d][2]);

			if (visited[na][nb][nc]) continue;
			visited[na][nb][nc] = visited[a][b][c] + 1;
			q.push({ na,nb,nc });
		}
	}
	return;
}

int main() {
	cin >> N;
	cin >> node.a >> node.b >> node.c;
	bfs(node.a, node.b, node.c);
	cout << visited[0][0][0] - 1;
	return 0;
}