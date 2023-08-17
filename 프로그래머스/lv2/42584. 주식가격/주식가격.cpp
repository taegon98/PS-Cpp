#include <string>
#include <vector>
#include <deque>
using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer(prices.size());
    deque<pair<int, int>> dq;
    
    for (int i = 0; i < prices.size(); i++) {
        while(dq.size() and dq.back().second > prices[i]) {
            answer[dq.back().first] = i - dq.back().first;
            dq.pop_back();
        }
        dq.push_back({i, prices[i]});
    }
    
    int idx = dq.back().first;
    for (auto var : dq) answer[var.first] = idx - var.first;
    
    return answer;
}