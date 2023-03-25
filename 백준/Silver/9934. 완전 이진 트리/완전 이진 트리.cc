#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int K, tmp;
vector<int> v;
vector<int> ret[14];

void go(int level, int s, int e) {
	if (s == e) {
		ret[level].push_back(v[s]);
		return;
	}
	int mid = (s + e) / 2;
	ret[level].push_back(v[mid]);
	go(level + 1, s, mid - 1);
	go(level + 1, mid + 1, e);
}

int main() {
	cin >> K;
	for (int i = 0; i < pow(2, K) - 1; i++) {
		cin >> tmp; v.push_back(tmp);
	}
	go(1, 0, v.size() - 1);

	for (int i = 1; i <= 10; i++) {
		if (ret[i].size() == 0) continue;
		for (int num : ret[i]) cout << num << " ";
		cout << "\n";
	}
}