#include <iostream>
#include <vector>
using namespace std;

int N, K, idx;
vector<int> v;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N >> K;
	for (int i = 1; i <= N; i++) v.push_back(i);

	cout << "<";
	for (int i = 1; i <= N; i++) {
		idx = (idx + K - 1) % v.size();
		if (i == N) cout << v[idx];
		else cout << v[idx] << ", ";
		v.erase(v.begin() + idx);
	}
	cout << ">";
}