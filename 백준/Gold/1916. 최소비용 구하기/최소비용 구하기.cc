#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define INF 1e9
int N, M, s, e, w, dist[1001], visited[1001];
vector<pair<int, int>> v[1001];
struct compare {
	bool operator()(pair<int, int>& a, pair<int, int>& b) {
		return a.second > b.second;
	}
};
priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq;

void dijkstra(int n) {
	pq.push({ n,0 });
	dist[n] = 0;
	while(pq.size()) {
		int node = pq.top().first;
		int weight = pq.top().second;
		pq.pop();
		
		if (visited[node]) continue;
		visited[node] = 1;

		for (auto var : v[node]) {
			if (dist[var.first] > var.second + weight) {
				dist[var.first] = var.second + weight;
				pq.push({ var.first, dist[var.first] });
			}
		}
		
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	for (int i = 0; i < 1001; i++) dist[i] = INF;
	cin >> N >> M;
	for (int i = 1; i <= M; i++) {
		cin >> s >> e >> w;
		v[s].push_back({ e,w });
	}
	cin >> s >> e;
	dijkstra(s);
	cout << dist[e];
}