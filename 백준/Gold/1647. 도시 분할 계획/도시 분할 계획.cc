#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct element {
	int v1, v2, w;
};
int N, M, ret, parent[100001];
element temp;
vector<element> v;

bool cmp(element& a, element& b) { return a.w < b.w; }

int find(int num) {
	if (!parent[num]) return num;
	else return parent[num] = find(parent[num]);
}

void Union(int a, int b) { parent[a] = b; }

void kruskal() {
	int edge = 0;
	for (auto var : v) {
		if (edge == N - 2) return;
		int n1 = find(var.v1);
		int n2 = find(var.v2);
		if (n1 != n2) {
			edge++;
			ret += var.w;
			Union(n1, n2);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> temp.v1 >> temp.v2 >> temp.w;
		v.push_back(temp);
	}
	sort(v.begin(), v.end(), cmp);
	kruskal();
	cout << ret;
}