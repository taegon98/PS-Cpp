#include <string>
#include <vector>
#include <deque>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    deque<pair<int, int>> q;
    for (int i = 0; i < progresses.size(); i++) {
        q.push_back({progresses[i], speeds[i]});
    }
    
    while(q.size()) {
        int cnt = 0;
        for (int i = 0; i < q.size(); i++) {
            q[i].first += q[i].second;
        }
        while (q.size()) {
            if (q.front().first < 100) break;
            else {
                q.pop_front();
                cnt++;
            }
        }
        if (cnt) answer.push_back(cnt);
    }
    
    return answer;
}