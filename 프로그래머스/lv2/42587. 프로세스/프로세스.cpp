#include <string>
#include <vector>
#include <deque>
using namespace std;
deque<pair<int, int>> q;

bool check(int n) {
    for (auto var : q) {
        if (var.second > n) return false;
    }
    return true;
}

int solution(vector<int> priorities, int location) {
    int answer = 0;
    for (int i = 0; i < priorities.size(); i++) {
        q.push_back({i, priorities[i]});
    }
    while(q.size()) {
        auto temp = q.front(); q.pop_front();
        if (!check(temp.second)) {
            q.push_back(temp);
        }
        else {
            answer++;
            if (temp.first == location) break;
        }
    }
    return answer;
}