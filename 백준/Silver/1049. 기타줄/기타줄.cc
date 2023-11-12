#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N, M, p, e;
vector<int> v1, v2;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> p >> e;
		v1.push_back(p);
		v2.push_back(e);
	}

	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());
	
	int package = N / 6;
	int each = N % 6;

	int ret1 = v1.front() * package + v2.front() * each;
	int ret2 = v1.front() * (package + 1);
	int ret3 = v2.front() * N;

	cout << min(min(ret1, ret2), ret3);
}