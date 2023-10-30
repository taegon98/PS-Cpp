#include <iostream>
#include <map>
using namespace std;
int N, ret, visited[1001];
char arr[] = { 'I','V','X','L' };
map<char, int> mp;

void go(int idx, int depth, int tot) {
	if (depth == N) {
		if (!visited[tot]) {
			visited[tot] = 1;
			ret++;
		}
		return;
	}
	for (int i = idx; i < 4; i++) {
		go(i, depth + 1, tot + mp[arr[i]]);
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N;
	mp['I'] = 1; mp['V'] = 5; mp['X'] = 10; mp['L'] = 50;

	go(0, 0, 0);
	cout << ret;
}