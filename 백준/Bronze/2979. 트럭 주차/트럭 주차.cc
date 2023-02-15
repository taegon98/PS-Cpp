#include <iostream>

using namespace std;

int main() {
	int cost[101] = { 0 };
	register int A, B, C, s, e, total_cost = 0;

	cin >> A >> B >> C;

	for (int i = 0; i < 3; i++) {
		cin >> s >> e;
		for (int j = s; j < e; j++)cost[j]++;
	}

	for (int i = 1; i < 101; i++) {
		if (cost[i] == 3) total_cost += (C * 3);
		else if (cost[i] == 2)total_cost += (B * 2);
		else if (cost[i] == 1)total_cost += A;
	}

	cout << total_cost;
	return 0;
}