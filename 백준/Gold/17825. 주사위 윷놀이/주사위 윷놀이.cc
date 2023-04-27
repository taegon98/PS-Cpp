#include <iostream>
using namespace std;
struct element {
	int p, f, alive;
};
element horse[4];
int ret = -987654321, pre_pos, dice[10], visited[32];
int ori[] = { 0,2,4,6,8,10,12,14,16,18,20,
22,24,26,28,30,32,34,36,38,40,22,
24,13,16,19,28,27,26,25,30,35 };

void go(int depth, int score) {
	if (depth == 10) {
		ret = max(ret, score);
		return;
	}
	for (int pos = 0; pos < 4; pos++) {
		if (!horse[pos].alive) continue;
		if ((horse[pos].p == 5 and horse[pos].f == 1) or horse[pos].f == 2) {
			element pre = horse[pos];
			horse[pos].p += dice[depth];
			if (horse[pos].f != 2) {
				horse[pos].f = 2;
				horse[pos].p += 17;
			}
			if (horse[pos].p >= 26 and horse[pos].p <= 28) horse[pos].p += 3;
			else if (pre.p >= 23 and pre.p <= 25) {
				if (horse[pos].p == 29) horse[pos].p = 20;
				else if (horse[pos].p > 29) horse[pos].p = 40;
			}
			else if (horse[pos].p == 32) horse[pos].p = 20;
			else if (horse[pos].p > 32) horse[pos].p = 40;

			if (pre.p == 20 or horse[pos].p == 40) {
				horse[pos].alive = 0;
				visited[pre.p] = 0;
				go(depth + 1, score);
				horse[pos].p = pre.p;
				visited[pre.p] = 1;
				horse[pos].alive = 1;
			}
			else {
				if (visited[horse[pos].p]) {
					horse[pos].p = pre.p;
					if (horse[pos].p == 5) horse[pos].f = 1;
					continue;
				}
				score += ori[horse[pos].p];
				visited[pre.p] = 0;
				visited[horse[pos].p] = 1;
				go(depth + 1, score);
				visited[pre.p] = 1;
				visited[horse[pos].p] = 0;
				score -= ori[horse[pos].p];
				horse[pos].p = pre.p;
				if (horse[pos].p == 5) horse[pos].f = 1;
			}
		}
		else if ((horse[pos].p == 10 and horse[pos].f == 1) or horse[pos].f == 3) {
			element pre = horse[pos];
			horse[pos].p += dice[depth];
			if (horse[pos].f != 3) {
				horse[pos].f = 3;
				horse[pos].p += 10;
			}
			if (horse[pos].p >= 23 and horse[pos].p <= 25) horse[pos].p += 6;
			else if (horse[pos].p == 26 or horse[pos].p == 32) horse[pos].p = 20;
			else if (horse[pos].p == 27 or horse[pos].p == 28
				or horse[pos].p > 32) horse[pos].p = 40;

			if (pre.p == 20 or horse[pos].p == 40) {
				horse[pos].alive = 0;
				visited[pre.p] = 0;
				go(depth + 1, score);
				horse[pos].p = pre.p;
				visited[pre.p] = 1;
				horse[pos].alive = 1;
			}
			else {
				if (visited[horse[pos].p]) {
					horse[pos].p = pre.p;
					if (horse[pos].p == 10) horse[pos].f = 1;
					continue;
				}
				score += ori[horse[pos].p];
				visited[pre.p] = 0;
				visited[horse[pos].p] = 1;
				go(depth + 1, score);
				visited[pre.p] = 1;
				visited[horse[pos].p] = 0;
				score -= ori[horse[pos].p];
				horse[pos].p = pre.p;
				if (horse[pos].p == 10) horse[pos].f = 1;
			}
		}
		else if ((horse[pos].p == 15 and horse[pos].f == 1) or horse[pos].f == 4) {
			element pre = horse[pos];
			horse[pos].p += dice[depth];
			if (horse[pos].f != 4) {
				horse[pos].f = 4;
				horse[pos].p += 10;
			}
			if (horse[pos].p == 32) horse[pos].p = 20;
			else if (horse[pos].p > 32) horse[pos].p = 40;

			if (pre.p == 20 or horse[pos].p == 40) {
				horse[pos].alive = 0;
				visited[pre.p] = 0;
				go(depth + 1, score);
				horse[pos].p = pre.p;
				visited[pre.p] = 1;
				horse[pos].alive = 1;
			}
			else {
				if (visited[horse[pos].p]) {
					horse[pos].p = pre.p;
					if (horse[pos].p == 15) horse[pos].f = 1;
					continue;
				}
				score += ori[horse[pos].p];
				visited[pre.p] = 0;
				visited[horse[pos].p] = 1;
				go(depth + 1, score);
				visited[pre.p] = 1;
				visited[horse[pos].p] = 0;
				score -= ori[horse[pos].p];
				horse[pos].p = pre.p;
				if (horse[pos].p == 15) horse[pos].f = 1;
			}
		}
		else if (horse[pos].f == 1) {
			element pre = horse[pos];
			horse[pos].p += dice[depth];
			if (pre.p == 20 or horse[pos].p > 20) {
				horse[pos].alive = 0;
				visited[pre.p] = 0;
				go(depth + 1, score);
				horse[pos].p = pre.p;
				visited[pre.p] = 1;
				horse[pos].alive = 1;
			}
			else {
				if (visited[horse[pos].p]) {
					horse[pos].p = pre.p;
					continue;
				}
				score += ori[horse[pos].p];
				visited[pre.p] = 0;
				visited[horse[pos].p] = 1;
				go(depth + 1, score);
				visited[pre.p] = 1;
				visited[horse[pos].p] = 0;
				score -= ori[horse[pos].p];
				horse[pos].p = pre.p;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	for (int i = 0; i < 10; i++) cin >> dice[i];
	for (int i = 0; i < 4; i++) {
		horse[i].alive = 1;
		horse[i].f = 1;
	}
	go(0, 0);
	cout << ret;
}