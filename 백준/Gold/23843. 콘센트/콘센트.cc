#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int N, M, temp, ret;
priority_queue<int, vector<int>, less<int>> pq;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> temp;
        pq.push(temp);
    }

    while (pq.size()) {
        vector<int> v;

        while (pq.size() and v.size() < M) {
            v.push_back(pq.top());
            pq.pop();
        }

        int diff = v.back();
        v.pop_back();
        ret += diff;

        for (auto var : v) {
            int n = var - diff;
            if (!n) continue;
            pq.push(n);
        }
    }
    cout << ret;
}