#include <string>
#include <vector>
#include <queue>
using namespace std;
priority_queue <int, vector<int>, greater<int>> pq;
vector<int> solution(int k, vector<int> score) {
    vector<int> answer;
    for (auto var : score) {
        bool ok = true;
        if (pq.size() >= k) {
            if (var > pq.top()) pq.pop();
            else ok = false;
        }
        if (ok) pq.push(var);
        answer.push_back(pq.top());
    }
    return answer;
}