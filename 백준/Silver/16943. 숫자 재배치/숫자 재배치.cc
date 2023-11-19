#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int B, C, visited[10];
string A;
vector<char> v;
vector<int> ret;

void go(int depth, string s) {

	if (depth == A.size()) {
		if (B > stoi(s)) {
			ret.push_back(stoi(s));
		}
		return;
	}

	for (int i = 0; i < v.size(); i++) {
		if (visited[i]) continue;
		if (depth == 0 and v[i] == '0') continue;
		visited[i] = 1;
		go(depth + 1, s + v[i]);
		visited[i] = 0;
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	cin >> A >> B;

	for (int i = 0; i < A.size(); i++) {
		v.push_back(A[i]);
	}

	go(0, "");
	if (!ret.size()) cout << -1;
	else {
		sort(ret.rbegin(), ret.rend());
		cout << ret[0];
	}
}