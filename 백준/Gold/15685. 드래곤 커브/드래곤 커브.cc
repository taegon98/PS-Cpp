#include <iostream>
#include <vector>
using namespace std;
int N, cur_y, cur_x, ret;
struct info {
	int x, y, d, g;
};
struct info tmp;
vector<info> v;
int arr[104][104];
int dy[4] = { 0,-1,0,1 }, dx[4] = { 1,0,-1,0 };
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> tmp.x >> tmp.y >> tmp.d >> tmp.g;
		arr[tmp.y][tmp.x] = 1;
		v.push_back(tmp);
	}
	for (int i = 0; i < v.size(); i++) {
		vector<int> vv, s;
		vv.push_back(v[i].d);
		int dir = vv.back();
		cur_y = v[i].y + dy[dir]; cur_x = v[i].x + dx[dir];
		arr[cur_y][cur_x] = 1;

		for (int j = 0; j < v[i].g; j++) {
			s = vv;
			while (s.size()) {
				dir = (s.back() + 1) % 4;
				cur_y += dy[dir]; cur_x += dx[dir];
				arr[cur_y][cur_x] = 1;
				vv.push_back(dir);
				s.pop_back();
			}
		}
	}
	for (int i = 0; i < 100; i++)
		for (int j = 0; j < 100; j++)
			if (arr[i][j] and arr[i][j + 1] and arr[i + 1][j] and arr[i + 1][j + 1]) ret++;
	cout << ret;
}