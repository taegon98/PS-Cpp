#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct element {
	int color;
	vector<int> l; //말번호,방향
};
struct Info {
	int y, x, d;
};
int N, K, y, x, d, ret = 1;
int dy[] = { 0,0,-1,1 }, dx[] = { 1,-1,0,0 }; //오른, 왼, 위, 아래
Info temp;
vector<Info> info; //좌표 저장
element arr[14][14];

bool check() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (arr[i][j].l.size() >= 4) return true;
		}
	}
	return false;
}

void go() {
	int turn = 0;
	for (int pos = 0; pos < info.size(); pos++) {
		turn++;
		auto a = info[pos];
		int ny, nx, i = 0, size = arr[a.y][a.x].l.size();
		bool ok = false;
		vector<int> tmp;
		if (info[pos].d == 1) {//오른쪽
			ny = a.y + dy[0];
			nx = a.x + dx[0];
			if (arr[ny][nx].color == 2 or ny < 1 or nx < 1 or ny > N or nx > N) {
				ny = a.y + dy[1];
				nx = a.x + dx[1];
				info[pos].d = 2;
				if (arr[ny][nx].color == 2 or ny < 1 or nx < 1 or ny > N or nx > N) continue;
			}
		}
		else if (info[pos].d == 2) {//왼쪽
			ny = a.y + dy[1];
			nx = a.x + dx[1];
			if (arr[ny][nx].color == 2 or ny < 1 or nx < 1 or ny > N or nx > N) {
				ny = a.y + dy[0];
				nx = a.x + dx[0];
				info[pos].d = 1;
				if (arr[ny][nx].color == 2 or ny < 1 or nx < 1 or ny > N or nx > N) continue;
			}
		}
		else if (info[pos].d == 3) {//위
			ny = a.y + dy[2];
			nx = a.x + dx[2];
			if (arr[ny][nx].color == 2 or ny < 1 or nx < 1 or ny > N or nx > N) {
				ny = a.y + dy[3];
				nx = a.x + dx[3];
				info[pos].d = 4;
				if (arr[ny][nx].color == 2 or ny < 1 or nx < 1 or ny > N or nx > N) continue;
			}
		}
		else if (info[pos].d == 4) {//아래
			ny = a.y + dy[3];
			nx = a.x + dx[3];
			if (arr[ny][nx].color == 2 or ny < 1 or nx < 1 or ny > N or nx > N) {
				ny = a.y + dy[2];
				nx = a.x + dx[2];
				info[pos].d = 3;
				if (arr[ny][nx].color == 2 or ny < 1 or nx < 1 or ny > N or nx > N) continue;
			}
		}
		while (size) {
			int h = arr[a.y][a.x].l[i];
			if (turn == h or ok) {
				tmp.push_back(h);
				arr[a.y][a.x].l.erase(
					remove(arr[a.y][a.x].l.begin(), arr[a.y][a.x].l.end(), h), arr[a.y][a.x].l.end());
				ok = true;
				info[h - 1].y = ny;
				info[h - 1].x = nx;
			}
			else i++;
			size--;
		}
		if (arr[ny][nx].color == 1) reverse(tmp.begin(), tmp.end());
		for (int i = 0; i < tmp.size(); i++)
			arr[ny][nx].l.push_back(tmp[i]);
		if (check()) {
			cout << ret;
			exit(0);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N >> K;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++)
			cin >> arr[i][j].color;
	}
	for (int i = 1; i <= K; i++) {
		cin >> temp.y >> temp.x >> temp.d;
		info.push_back(temp);
		arr[temp.y][temp.x].l.push_back(i);
	}
	for (; ret <= 1000; ret++) {
		go();
	}
	cout << -1;
}