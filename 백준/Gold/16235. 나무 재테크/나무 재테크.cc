#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
vector<int> v;
int N, M, K, y, x, age, ret, add[14][14];
int dy[] = { -1,-1,-1,0,1,1,1,0 }, dx[] = { -1,0,1,1,1,0,-1,-1 };

bool cmp(int& a, int& b) { return a < b; }

struct element {
	int food;
	vector<int> v;
};
element land[14][14];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> add[i][j];
			land[i][j].food = 5;
		}
	}
	for (int i = 0; i < M; i++) {
		cin >> y >> x >> age;
		land[y][x].v.push_back(age);
	}

	for (int tc = 1; tc <= K; tc++) {
		ret = 0;		

		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++)
				if (land[i][j].v.size()) {
					sort(land[i][j].v.begin(), land[i][j].v.end(), cmp);
				}
		}

		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				int add_tmp = 0;
				vector<int> tmp;
				for (int k = 0; k < land[i][j].v.size(); k++) {
					int curr = land[i][j].v[k];
					int rem = land[i][j].food - curr;
					if (rem < 0) {
						add_tmp += (curr / 2);
					}
					else {
						land[i][j].food = rem;
						tmp.push_back(curr + 1);
					}
				}
				land[i][j].food += add_tmp;
				land[i][j].v = tmp;
			}
		}

		
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				for (int k = 0; k < land[i][j].v.size(); k++) {
					if (land[i][j].v[k] % 5 == 0) {
						for (int k = 0; k < 8; k++) {
							int ny = i + dy[k];
							int nx = j + dx[k];
							if (ny < 1 or nx < 1 or ny > N or nx > N) continue;
							land[ny][nx].v.push_back(1);
						}
					}
				}
			}
		}

		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++)
				land[i][j].food += add[i][j];
		}

		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++)
				if (land[i][j].v.size()) ret += land[i][j].v.size();
		}
	}
	cout << ret;
}