#include <iostream>
#include <unordered_map>
using namespace std;
typedef long long ll;
ll N, M, ret;
string tmp;
unordered_map<string, int> mp;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> tmp; mp[tmp]++;
	}
	for (int i = 0; i < M; i++) {
		cin >> tmp;
		if (mp[tmp]) ret++;
	}
	cout << ret;
}