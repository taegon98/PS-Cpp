#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct cmp_greater {
	bool operator()(const pair<int, int>& A, pair<int, int>& B) {
		return A.second < B.second;
	}
};

struct cmp_less {
	bool operator()(const pair<int, int>& A, pair<int, int>& B) {
		return A.second > B.second;
	}
};

priority_queue<pair<int, int>, vector<pair<int, int>>, cmp_greater> pq1;
priority_queue<pair<int, int>, vector<pair<int, int>>, cmp_less> pq2;

int main() {
	for (int tc = 1; tc <= 10; tc++) {
		int n, m;
		cin >> n;
		vector<int> v;

		for (int i = 0; i < 100; i++) {
			cin >> m;
			v.push_back(m);
			pq1.push({ i, m });
			pq2.push({ i, m });
		}

		while (n--) {
			v[pq1.top().first]--;
			v[pq2.top().first]++;

			while (pq1.size()) pq1.pop();
			while (pq2.size()) pq2.pop();

			for (int i = 0; i < 100; i++) {
				pq1.push({ i, v[i] });
				pq2.push({ i, v[i] });
			}
		}

		cout << "#" << tc << " " << pq1.top().second - pq2.top().second << "\n";
	}
}