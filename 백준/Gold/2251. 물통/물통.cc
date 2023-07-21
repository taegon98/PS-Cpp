#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int A, B, C, visited[201][201][201];
vector<int> v;

void go(int a, int b, int c) {
	if (!a) v.push_back(c);
	if (c) {
		if (a != A) {
			int temp = min(A - a, c);
			if (!visited[a + temp][b][c - temp]) {
				visited[a + temp][b][c - temp] = 1;
				go(a + temp, b, c - temp);
			}	
		}
		if (b != B) {
			int temp = min(B - b, c);
			if (!visited[a][b + temp][c - temp]) {
				visited[a][b + temp][c - temp] = 1;
				go(a, b + temp, c - temp);
			}
		}
	}
	if (b) {
		if (a != A) {
			int temp = min(A - a, b);
			if (!visited[a + temp][b - temp][c]) {
				visited[a + temp][b - temp][c] = 1;
				go(a + temp, b - temp, c);
			}	
		}
		if (c != C) {
			int temp = min(C - c, b);
			if (!visited[a][b - temp][c + temp]) {
				visited[a][b - temp][c + temp] = 1;
				go(a, b - temp, c + temp);
			}
				
		}
	}
	if (a) {
		if (b != B) {
			int temp = min(B - b, a);
			if (!visited[a - temp][b + temp][c]) {
				visited[a - temp][b + temp][c] = 1;
				go(a - temp, b + temp, c);
			}
				
		}
		if (c != C) {
			int temp = min(C - c, a);
			if (!visited[a - temp][b][c + temp]) {
				visited[a - temp][b][c + temp] = 1;
				go(a - temp, b, c + temp);
			}
				
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> A >> B >> C;
	visited[0][0][C] = C;
	go(0, 0, C);
	sort(v.begin(), v.end());
	for (auto var : v) cout << var << " ";
}