#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <vector>

using namespace std;

unordered_map<int, int> Map1;	//정렬 조건1 : counting
unordered_map<int, int> Map2;	//정렬 조건2 : 등장 순서

bool cmp(pair<int, int>& a, pair<int, int>& b) {
	if (a.second == b.second) {
		return Map2[a.first] < Map2[b.first];
	}
	return a.second > b.second;
}

int main() {
	
	int N, C, tmp;
	cin >> N >> C;

	for (int i = 0; i < N; i++) {
		cin >> tmp;
		if (Map1.find(tmp) == Map1.end()) {
			Map1.insert(make_pair(tmp, 1));
			Map2.insert(make_pair(tmp, i + 1));
		}
		else Map1[tmp]++;
	}
	
	vector<pair<int, int>> v(Map1.begin(), Map1.end());
	sort(v.begin(), v.end(), cmp);
	
	for (auto iter : v) {
		for (int i = 0; i < iter.second; i++) cout << iter.first << " ";
	}

	return 0;
}