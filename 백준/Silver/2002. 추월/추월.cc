#include <iostream>
#include <map>
using namespace std;
map<string, int> mp;
int N, visited[1001], ret;
string str;

bool check(int idx) {
	for (int i = 0; i < idx; i++) {
		if (!visited[i]) return false;
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> str;
		mp[str] = i;
	}

	for (int i = 0; i < N; i++) {
		cin >> str;
		if (!check(mp[str])) ret++;
		visited[mp[str]] = 1;
	}

	cout << ret;
}