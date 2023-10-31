#include <iostream>
#include <vector>
using namespace std;
string s;
int visited[11], alpha[27];
int ret;
vector<int> v;

void go(int depth, string str) {
	
	if (depth == s.size()) {
		ret++;
		return;
	}

	for (int i = 0; i < s.size(); i++) {
		if (visited[i]) continue;
		if (str.size() and str[str.size() - 1] == s[i]) continue;
		visited[i] = 1;
		go(depth + 1, str + s[i]);
		visited[i] = 0;
	}

}


int main() {

	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int cnt = 1;

	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		alpha[s[i] - 97]++;
	}
	for (int i = 0; i < 26; i++) {
		if (alpha[i] > 1) v.push_back(alpha[i]);
	}
	for (auto var : v) {
		int temp = 1;
		for (int i = 1; i <= var; i++) {
			temp *= i;
		}
		cnt *= temp;
	}
	go(0, "");

	cout << ret / cnt;
}