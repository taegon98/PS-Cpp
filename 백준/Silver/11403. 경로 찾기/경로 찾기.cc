#include <iostream>
#include <vector>
using namespace std;
int N, ok;
vector<int> v[101];

bool go(int s, int target, int visited[]) {
	for (auto var : v[s]) {
		if (var == target) return true;
		if (visited[var]) continue;
		visited[var] = 1;
		if (go(var, target, visited)) return true;
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> ok;
			if (ok) v[i].push_back(j);
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int visited[101] = { 0 };
			visited[i] = 1;
			if (go(i, j, visited)) cout << "1 ";
			else cout << "0 ";
		}
		cout << "\n";
	}
}