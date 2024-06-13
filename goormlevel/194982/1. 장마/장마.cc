#include <iostream>
#include <vector>
using namespace std;
int main() {
	int N, M;
	int house[1001];
	vector<pair<int, int>> v;
	int from, to;
	
	cin >> N >> M;
	
	for (int i = 1; i <= N; i++) {
		cin >> house[i];	
	}
	
	for (int i = 1; i <= M; i++) {
		cin >> from >> to;
		v.push_back({from, to});
		
		for (int j = from; j <= to; j++) {
			house[j]++;
		}
		
		if (i % 3 == 0) {
			int visited[1001] = {0};
			for (int j = i - 3; j < i; j++) {
				for (int k = v[j].first; k <= v[j].second; k++) {
					if (visited[k]) continue;
					visited[k] = 1;
					house[k]--;
				}
			}
		}
	}
	
	for (int i = 1; i <= N; i++) {
		cout << house[i] << " ";
	}
}