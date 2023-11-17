#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;
unordered_map<string, int> mp1, mp2;
vector<string> v[101];
int N, M, num;
string s;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> s;
		mp1[s] = i;
		v[i].push_back(s);
		cin >> num;
		for (int j = 0; j < num; j++) {
			cin >> s;
			v[i].push_back(s);
			mp2[s] = i;
		}
	}

	for (int i = 0; i < M; i++) {
		cin >> s >> num;
		if (num == 1) {
			cout << v[mp2[s]].front() << "\n";
		}
		else if (num == 0) {
			vector<string> temp;
			for (int i = 1; i < v[mp1[s]].size(); i++) {
				temp.push_back(v[mp1[s]][i]);
			}
			sort(temp.begin(), temp.end());
			for (auto var : temp) cout << var << "\n";
		}
	}
}