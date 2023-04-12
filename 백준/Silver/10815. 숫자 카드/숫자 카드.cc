#include <iostream>
#include <unordered_map>
using namespace std;
typedef long long ll;
ll N, M, tmp;
unordered_map<int, int> mp;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> tmp; mp[tmp]++;
	}
	cin >> M;
	for (int i = 1; i <= M; i++) {
		cin >> tmp;
		if (mp[tmp]) cout << 1 << " ";
		else cout << 0 << " ";
	}
}