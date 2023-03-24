#include <iostream>
#include <unordered_map>
using namespace std;

int N, M, tmp;
unordered_map<int,int> map;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		map[tmp]++;
	}

	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> tmp;
		if (map.find(tmp) != map.end()) cout << 1 << "\n";
		else cout << 0 << "\n";
	}
	return 0;
}