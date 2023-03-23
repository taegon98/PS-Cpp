#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int k;
char tmp;
vector<char> op;
vector<int> num = { 0,1,2,3,4,5,6,7,8,9 };
vector<int> com;
vector<string> ret;

void combi(int idx, int cnt) {
	if (cnt == k + 1) {
		do {
			bool ok = true;
			for (int i = 0; i < k; i++) {
				if (op[i] == '<') {
					if (com[i] >= com[i + 1]) {
						ok = false; break;
					}
				}
				else if (op[i] == '>') {
					if (com[i] <= com[i + 1]) {
						ok = false; break;
					}
				}
			}
			if (ok) {
				string tmp = "";
				for (int i = 0; i < k + 1; i++) tmp += to_string(com[i]);
				ret.push_back(tmp);
			}
		} while (next_permutation(com.begin(), com.end()));
	}
	for (int i = idx; i < 10; i++) {
		com.push_back(i);
		combi(i + 1, cnt + 1);
		com.pop_back();
	}
}

int main() {
	cin >> k;
	for (int i = 0; i < k; i++) {
		cin >> tmp;
		op.push_back(tmp);
	}

	combi(0, 0);
	cout << ret[ret.size() - 1] << "\n";
	cout << ret[0];
	return 0;
}