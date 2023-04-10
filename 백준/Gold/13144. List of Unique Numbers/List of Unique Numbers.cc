#include <iostream>
#include <vector>
using namespace std;
long long N, l, r, tmp, ret;
bool visited[100004];
vector<int> v;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> tmp; v.push_back(tmp);
	}
	while (r < N) {
		while (visited[v[r]]) {
			visited[v[l]] = false;
			l++;
		}	
		visited[v[r]] = true;
		ret += (r - l + 1);
		r++;
	}
	cout << ret;
}