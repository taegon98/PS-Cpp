#include <iostream>
#include <map>
#include <vector>
using namespace std;
int arr[21][21], ppl[401][4], N, s, close[4], ret = 0;
int dy[] = { -1,1,0,0 }, dx[] = { 0,0,-1,1 };
map<int, pair<int, int>> mp;
map<int, int> mp2;

void cal (int temp[21][21], pair<int, int> coord) {
	for (int i = 0; i < 4; i++) {
		int y = coord.first + dy[i];
		int x = coord.second + dx[i];

		if (y < 1 or x< 1 or y > N or x > N or arr[y][x]) continue;
		temp[y][x]++;
	}
}

void cal2(int temp[21][21]) {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (arr[i][j]) continue;
			temp[i][j]++;
			for (int k = 0; k < 4; k++) {
				int y = i + dy[k];
				int x = j + dx[k];
				
				if (y < 1 or x< 1 or y > N or x > N or arr[y][x]) continue;
				temp[i][j]++;
			}
		}
	}
}

void cal3(int temp[21][21], pair<int, int> coord) {
	for (int i = 0; i < 4; i++) {
		int y = coord.first + dy[i];
		int x = coord.second + dx[i];

		if (y < 1 or x < 1 or y > N or x > N or arr[y][x]) continue;
		temp[coord.first][coord.second]++;
	}
}

void cal4() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			int num = arr[i][j], target, cnt = 0;
			for (int k = 0; k < 4; k++) {
				int y = i + dy[k];
				int x = j + dx[k];

				if (y < 1 or x < 1 or y > N or x > N ) continue;
				target = arr[y][x];
				for (int l = 0; l < 4; l++) {
					if (ppl[num][l] == target) {
						cnt++; break;
					}
				}
			}
			ret += mp2[cnt];
		}
	}
}

void check2(vector<pair<int, int>> v) {
	int temp[21][21] = { 0 };
	int max_val = 0;
	pair<int, int> p;

	if(!v.size()) cal2(temp);
	else {
		for (auto var : v) cal3(temp, var);
	}
	
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (temp[i][j] > max_val) {
				max_val = temp[i][j];
				p.first = i; p.second = j;
			}
		}
	}
	if (!max_val) {
		mp[s] = { v[0].first, v[0].second };
		arr[v[0].first][v[0].second] = s;
	}
	else {
		mp[s] = { p.first, p.second };
		arr[p.first][p.second] = s;
	}
}

void check(int temp[21][21]) {
	vector<pair<int, int>> v;
	int max_val = 1;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (temp[i][j] > max_val) {
				max_val = temp[i][j];
			}
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (max_val == temp[i][j]) {
				v.push_back({ i,j });
			}
		}
	}

	if (v.size() == 1) {
		mp[s] = { v[0].first, v[0].second };
		arr[v[0].first][v[0].second] = s;
	}
	else check2(v);
}

void print() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cout << arr[i][j] << " ";
		}
		cout << "\n";
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N;
	mp2[0] = 0; mp2[1] = 1; mp2[2] = 10; mp2[3] = 100; mp2[4] = 1000;
	for (int i = 0; i < N * N; i++) {
		int temp[21][21] = { 0 };
		cin >> s >> close[0] >> close[1] >> close[2] >> close[3];
		ppl[s][0] = close[0]; 
		ppl[s][1] = close[1];
		ppl[s][2] = close[2];
		ppl[s][3] = close[3];

		if (!mp.size()) {
			mp[s] = { 2,2 };
			arr[2][2] = s;
			continue;
		}
		for (int j = 0; j < 4; j++) {
			if (mp.find(close[j]) == mp.end()) continue;
			cal(temp, mp[close[j]]);
		}
	    check(temp);
		//print();
	}
	cal4();
	//print();
	cout << ret;
}