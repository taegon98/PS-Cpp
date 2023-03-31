#include <iostream>
#include <vector>
#include <string.h>
using namespace std;
int T, N, M, A, B;
int visited[1004];
int go(int pos, vector<int> vec[1004], int depth) {
	if (visited[pos]) return 0;
	visited[pos] = 1;
	for (int n : vec[pos]) {
		if (!visited[n]) depth += go(n, vec, 1);
	}
	return depth;
}

int main() {
	cin >> T;
	for (int tc = 0; tc < T; tc++) {
		vector<int> v[1004];
		memset(visited, 0, sizeof(visited));
		int root = 0, depth = 0;
		cin >> N;
		cin >> M;
		for (int i = 1; i <= M; i++) {
			cin >> A >> B;
			v[A].push_back(B);
			v[B].push_back(A);
			if (!root) root = A;
		}
		if (M != N - 1) {
			cout << "graph\n"; continue;
		}
		if (go(root, v, 1) == N) cout << "tree\n";
		else cout << "graph\n";
	}
}