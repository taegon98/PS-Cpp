#include <iostream>
#include <vector>

using namespace std;

vector<int> num;
vector<int> op;
int ret = -987654321;

int calc(char oper, int a, int b) {
	if (oper == '+') return a + b;
	else if (oper == '-') return a - b;
	else if (oper == '*') return a * b;
}

void go(int idx, int tot) {
	if (idx == num.size() - 1) {
		ret = max(ret, tot);
		return;
	}
	go(idx + 1, calc(op[idx], tot, num[idx + 1]));
	if (idx + 2 <= num.size() - 1) {
		int n = calc(op[idx + 1], num[idx + 1], num[idx + 2]);
		go(idx + 2, calc(op[idx], tot, n));
	}
}

int main() {
	int N, tmp1;
	char tmp2;
	cin >> N;
	for (int i = 0; i < N; i++) {
		if (i % 2 == 0) {
			cin >> tmp1;
			num.push_back(tmp1);
		}
		else {
			cin >> tmp2;
			op.push_back(tmp2);
		}
	}
	go(0, num[0]);
	cout << ret;
	return 0;
}