#include <iostream>
using namespace std;
int N, M, from, to, arr[100001], psum[100001];
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
		psum[i] = psum[i - 1] + arr[i];
	}
	for (int i = 1; i <= M; i++) {
		cin >> from >> to;
		cout << psum[to] - psum[from - 1] << "\n";
	}
}