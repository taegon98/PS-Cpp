#include <iostream>
#include <vector>
using namespace std;
int T, K, tmp, dir, ret, arr[1004][8], pointer[1004];
vector<pair<int, int>> v;

void go() {
	for (pair<int, int> p : v) {
		int check[1004] = { 0 };
		tmp = p.first;
		dir = p.second;
		check[tmp] = dir;
		while (1) {
			if (tmp <= 1) break;
			int c1 = (pointer[tmp] + 6) % 8;
			int c2 = (pointer[tmp - 1] + 2) % 8;
			if (arr[tmp][c1] == arr[tmp - 1][c2]) break;
			else {
				dir *= -1;
				check[tmp - 1] = dir;
			}
			tmp--;
		}
		while (1) {
			if (tmp >= T) break;
			int c1 = (pointer[tmp] + 2) % 8;
			int c2 = (pointer[tmp + 1] + 6) % 8;
			if (arr[tmp][c1] == arr[tmp + 1][c2]) break;
			else {
				dir *= -1;
				check[tmp + 1] = dir;
			}
			tmp++;
		}
		for (int i = 1; i <= T; i++) {
			if (check[i] == -1) pointer[i] = (pointer[i] + 1) % 8;
			else if (check[i] == 1) pointer[i] = (pointer[i] + 7) % 8;
		}
	}
	
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> T;
	string str;
	for (int i = 1; i <= T; i++) {
		cin >> str;
		for (int k = 0; k < str.size(); k++)
			arr[i][k] = str[k] - '0';
	}
	cin >> K;
	for (int i = 0; i < K; i++) {
		cin >> tmp >> dir;
		v.push_back({ tmp,dir });
	}
	go();
	for (int i = 1; i <= T; i++) {
		if (arr[i][pointer[i]] == 1) ret++;
	}
	cout << ret;
}