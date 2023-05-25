#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct element {
	int a, b, w;
};
int N, M, ret, cnt, parent[10001];
element tmp;
vector<element> v;

bool cmp(element& a, element& b) { return a.w < b.w; }
int find(int n) {
	while (1) {
		if (!parent[n]) return n;
		else n = parent[n];
	}
}

void Union(int a, int b) {
	if (a >= b)
		parent[a] = b;
	else
		parent[b] = a;
}
void kruskal() {
	for (auto num : v) {
		if (cnt == N - 1) return;
		int fnum1 = find(num.a);
		int fnum2 = find(num.b);
		if (fnum1 != fnum2) {
			cnt++;
			ret += num.w;
			Union(fnum1, fnum2);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> tmp.a >> tmp.b >> tmp.w;
		v.push_back(tmp);
	}
	sort(v.begin(), v.end(), cmp);
	kruskal();
	cout << ret;
}