#include <iostream>
#include <vector>
using namespace std;
int N, visited[10], ret = 1000000001;
pair<int, int> temp;
vector<pair<int, int>> v;

void go(int depth, int s, int b, int size) {
	if (depth == size) {
		ret = min(ret, abs(s - b));
		return;
	}
	for (int i = depth; i < N; i++) 
		go(i + 1, s * v[i].first, b + v[i].second, size);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> temp.first >> temp.second;
		v.push_back(temp);
	}
	for (int i = 1; i <= N; i++)
		go(0, 1, 0, i);
	cout << ret;
}