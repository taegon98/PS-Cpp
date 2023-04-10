#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int N, temp, ret = 987654321;
int arr[24][24];
bool visited[24];

void cal() {
	vector<int> v1, v2;
	int tmp1 = 0, tmp2 = 0;
	for (int i = 1; i <= N; i++) {
		if (visited[i]) v1.push_back(i);
		else v2.push_back(i);
	}

	for (int i = 0; i < v1.size(); i++) {
		for (int j = i + 1; j < v1.size(); j++) {
			tmp1 += (arr[v1[i]][v1[j]] + arr[v1[j]][v1[i]]);
		}
	}
	for (int i = 0; i < v2.size(); i++) {
		for (int j = i + 1; j < v2.size(); j++) {
			tmp2 += (arr[v2[i]][v2[j]] + arr[v2[j]][v2[i]]);
		}
	}
	ret = min(ret, abs(tmp1 - tmp2));
}

void go(int depth, int idx) {
	if (depth == N / 2) {
		cal(); return;
	}
	for (int i = idx; i <= N; i++) {
		if (!visited[i]) {
			visited[i] = true;
			go(depth + 1, i + 1);
			visited[i] = false;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> temp;
			if (i == j) arr[i][j] = 0;
			else arr[i][j] = temp;
		}
	}
	go(0, 1);
	cout << ret << "\n";
}