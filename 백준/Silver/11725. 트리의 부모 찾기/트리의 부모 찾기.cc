#include <iostream>
#include <vector>
using namespace std;
int N, n1, n2;
vector<int> v[100001];
int parent[100001], visited[100001];

void go(int n) {
	for (auto var : v[n]) {
		if (!visited[var]) {
			visited[var] = 1;
			parent[var] = n;
			go(var);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 0; i < N - 1; i++) {
		cin >> n1 >> n2;
		v[n1].push_back(n2);
		v[n2].push_back(n1);
	}
	go(1);
	for (int i = 2; i <= N; i++) cout << parent[i] << "\n";
}