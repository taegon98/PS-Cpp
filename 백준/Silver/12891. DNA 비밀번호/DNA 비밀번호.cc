#include <iostream>
using namespace std;
int S, P, a, c, g, t, ret;
string tmp, s = "z";
struct element {
	int a, c, g, t;
};
element psum[1000001];


int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> S >> P >> tmp;
	cin >> a >> c >> g >> t;
	s += tmp;
	int idx = P;

	if (s[1] == 'A') psum[1].a = 1;
	else if (s[1] == 'C') psum[1].c = 1;
	else if (s[1] == 'G') psum[1].g = 1;
	else psum[1].t = 1;

 	for (int i = 2; i <= S; i++) {
		psum[i] = psum[i - 1];
		if (s[i] == 'A') psum[i].a = psum[i - 1].a + 1;
		else if (s[i] == 'C') psum[i].c = psum[i - 1].c + 1;
		else if (s[i] == 'G') psum[i].g = psum[i - 1].g + 1;
		else psum[i].t = psum[i - 1].t + 1;
	}

	while (1) {
		int temp_a = psum[idx].a - psum[idx - P].a;
		int temp_c = psum[idx].c - psum[idx - P].c;
		int temp_g = psum[idx].g - psum[idx - P].g;
		int temp_t = psum[idx].t - psum[idx - P].t;

		if (temp_a >= a and temp_c >= c and temp_g >= g and temp_t >= t) ret++;
		idx++;
		if (idx == S + 1) break;
	}
	cout << ret;
}