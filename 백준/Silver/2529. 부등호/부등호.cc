#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int k;
char tmp;
vector<char> op;
vector<string> ret;
int check[10];

bool ok(char a, char b, char op) {
	if (op == '<') return a < b;
	else if (op == '>') return a > b;
}

void combi(int idx, string num) {
	if (idx == k + 1) {
		ret.push_back(num);
		return;
	}
	for (int i = 0; i < 10; i++) {
		if (check[i]) continue;
		if (idx == 0 || ok(num[idx - 1], i + '0', op[idx - 1])) {
			check[i] = 1;
			combi(idx + 1, num + to_string(i));
			check[i] = 0;
		}
	}
}

int main() {
	cin >> k;
	for (int i = 0; i < k; i++) {
		cin >> tmp;
		op.push_back(tmp);
	}

	combi(0, "");
	sort(ret.begin(), ret.end());
	cout << ret[ret.size() - 1] << "\n";
	cout << ret[0];
	return 0;
}