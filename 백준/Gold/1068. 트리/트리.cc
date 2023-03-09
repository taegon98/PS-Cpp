#include <iostream>
using namespace std;

int N, D, ret;
struct Tree {
	int parent;
	bool alive;
};
Tree tree[54];

void delete_node(int num) {
	for (int i = 0; i < N; i++) {
		if (tree[i].parent == num and tree[i].alive) {
			tree[i].alive = false;
			delete_node(i);
		}
	}
}

int cnt_leaf(int s) {
	for (int i = 0; i < N; i++) {
		if (tree[i].alive and tree[i].parent == s) return 0;
	}
	return 1;
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> tree[i].parent;
		tree[i].alive = true;
	}
	cin >> D;

	tree[D].alive = false;
	delete_node(D);

	for (int i = 0; i < N; i++) {
		if (tree[i].alive) ret += cnt_leaf(i);
	}
	cout << ret;
	return 0;
}