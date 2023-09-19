#include <string>
#include <vector>
#include <stack>
#include <deque>
using namespace std;
stack<int> s;
deque<int> dq;
int solution(vector<int> order) {
    int answer = 0;
    int cur = 0;

    for (int i = 1; i <= order.size(); i++) dq.push_back(i);
    
    while(dq.size()) {
        int target = order[cur++];
        
        for (auto var : dq) {
            if (target == var) {
                answer++;
                dq.pop_front();
                break;
            }
            else {
                if (s.size() and s.top() == target) {
                    s.pop();
                    answer++;
                    break;
                }
                else s.push(var);
                dq.pop_front();
            } 
        }
    }
    
    while(s.size()) {
        if (s.top() == order[cur++]) {
            answer++;
            s.pop();
        }
        else break;
    }
    
    return answer;
}