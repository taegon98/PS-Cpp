#include <iostream>
using namespace std;
typedef long long ll;
struct element {
	ll t, a, h;
};
ll N, H, low = 1, high = 9e18, mid, ret;
element e[124000];

bool go(ll hp) {
	ll cur_hp = hp;
	ll cur_atk = H;

	for (int i = 1; i <= N; i++) {
		if (e[i].t == 1) {
			ll cnt = e[i].h / cur_atk;
			if(e[i].h % cur_atk) cnt++;
			cnt--;
			if (cur_hp - e[i].a * cnt <= 0) return false;
			else cur_hp -= (e[i].a * cnt);
		}
		else if (e[i].t == 2) {
			cur_atk += e[i].a;
			cur_hp = cur_hp + e[i].h < hp ? cur_hp + e[i].h : hp;
		}
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(); cout.tie(0);
	cin >> N >> H;
	for (int i = 1; i <= N; i++) cin >> e[i].t >> e[i].a >> e[i].h;
	while (low <= high) {
		mid = (low + high) / 2;
		if (go(mid)) {
			ret = mid;
			high = mid - 1;
		}
		else low = mid + 1;
	}
	cout << ret;
}