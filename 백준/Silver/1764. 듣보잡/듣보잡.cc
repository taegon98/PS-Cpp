#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;
unordered_map <string, int> ump;
vector<string> v;
int N, M, ret;
string tmp;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> tmp; ump[tmp]++;
	}
	for (int i = 0; i < M; i++) {
		cin >> tmp;
		if (ump[tmp]) v.push_back(tmp), ret++;
	}
	sort(v.begin(), v.end());
	cout << ret << "\n";
	for (string str : v) cout << str << "\n";
}