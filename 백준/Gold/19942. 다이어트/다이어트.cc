#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int N, mp, mf, ms, mv, ret = 987654321;
vector<int> idx;
struct Element {
	int p, f, s, v, c;
};
Element element[16];

void update(int n) {
	idx.clear();
	for (int i = 0; i <= N; i++) {
		if (n & (1 << i)) idx.push_back(i + 1);
	}
}

void check(Element e, int num) {
	int j;
	bool ok = false;
	if (e.p >= mp and e.f >= mf and e.s >= ms and e.v >= mv) {
		if (e.c < ret) {
			ret = e.c;
			update(num);
		}
		else if (e.c == ret) {
			vector<int> tmp;
			for (int i = 0; i <= N; i++) if (num & (1 << i)) tmp.push_back(i + 1);

			for (j = 0; j < tmp.size(); j++) {
				if (j == idx.size()) return;
				else if (j == tmp.size() and ok) {
					update(num); return;
				}
				if (tmp[j] < idx[j]) {
					update(num); return;
				}
				else if (tmp[j] == idx[j]) ok = true;
				else if (tmp[j] > idx[j]) {
					ok = false; break;
				}
			}
			if (ok) update(num);
		}
	}
}

void go(int n) {
	Element tmp = { 0,0,0,0,0 };
	for (int i = 0; i <= N; i++) {
		if (n & (1 << i)) {
			tmp.p += element[i].p;
			tmp.f += element[i].f;
			tmp.s += element[i].s;
			tmp.v += element[i].v;
			tmp.c += element[i].c;
		}
	}
	check(tmp, n);
}

int main() {
	cin >> N;
	cin >> mp >> mf >> ms >> mv;

	for (int i = 0; i < N; i++) {
		cin >> element[i].p >> element[i].f >> element[i].s >> element[i].v >> element[i].c;
	}
	for (int i = 1; i <= pow(2, N); i++) go(i);

	if (idx.empty()) cout << "-1";
	else {
		cout << ret << "\n";
		for (int value : idx) cout << value << " ";
	}
}