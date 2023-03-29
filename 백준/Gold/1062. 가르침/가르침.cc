#include <iostream>
#include <vector>
using namespace std;

int N, K, ret = -987654321;
vector<string> str;
string tmp;
int alpha[26];

void go() {
	int cnt = 0;
	for (string s : str) {
		bool ok = true;
		for (int i = 4; i < s.size() - 4; i++) {
			if (!alpha[s[i] - 'a']) {
				ok = false; break;
			}
		}
		if (ok) cnt++;
	}
	ret = max(ret, cnt);
}

void combi(int idx, int depth) {
	if (depth == K - 5) {
		go();
		return;
	}
	for (int i = idx; i < 26; i++) {
		if (alpha[i]) continue;
		alpha[i] = 1;
		combi(i + 1, depth + 1);
		alpha[i] = 0;
	}
}

int main() {
	ios_base::sync_with_stdio(false); cout.tie(nullptr); cin.tie(nullptr);
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> tmp; str.push_back(tmp);
	}

	alpha[0] = 1;
	alpha[2] = 1;
	alpha[8] = 1;
	alpha[13] = 1;
	alpha[19] = 1;

	if (K < 5) {
		cout << 0;
	}
	else if (K == 5) {
		go();
		cout << ret;
	}
	else {
		combi(0, 0);
		cout << ret;
	}
	return 0;
}