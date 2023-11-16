#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int N, M, temp;

struct element {
	int n, recom, num;
};
vector<element> v;
vector<int> ret;
element e;

bool cmp(element a, element b) {
	if (a.recom == b.recom) {
		return a.n > b.n;
	}
	return a.recom > b.recom;
}

int check(int temp) {
	for (int i = 0; i <v.size(); i++) {
		if (v[i].num == temp) return i;
	}
	return -1;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		cin >> temp;
		int idx = check(temp);

		if (idx != -1) {
			v[idx].recom++;
		}
		else if (v.size() < N) {
			e.n = i;
			e.num = temp;
			e.recom = 1;
			v.push_back(e);
		}
		else {
			v.pop_back();
			e.n = i;
			e.num = temp;
			e.recom = 1;
			v.push_back(e);
		}
		sort(v.begin(), v.end(), cmp);
	}
	for (auto var : v) {
		ret.push_back(var.num);
	}
	sort(ret.begin(), ret.end());
	for (auto var : ret) cout << var << " ";
}