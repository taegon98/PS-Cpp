#include <string>
#include <vector>
#include <deque>
using namespace std;
typedef long long ll;

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = 0;
    deque<ll> q1, q2;
    ll sum_1 = 0, sum_2 = 0, sum_half = 0;
    
    for (auto var : queue1) {
        sum_1 += var;
        q1.push_back(var);
    }
    for (auto var : queue2) {
        sum_2 += var;
        q2.push_back(var);
    }
    sum_half = (sum_1 + sum_2) / 2;
    
    while(1) {
        if (sum_1 == sum_2) break;
        if (q1.empty() or q2.empty() or answer >= queue1.size() * 4) {
            answer = -1;
            break;
        }
        
        if (sum_1 < sum_half) {
            q1.push_back(q2.front());
            sum_1 += q2.front();
            sum_2 -= q2.front();
            q2.pop_front();
        }
        else if (sum_1 > sum_half) {
            q2.push_back(q1.front());
            sum_1 -= q1.front();
            sum_2 += q1.front();
            q1.pop_front();
        }
        answer++;
    }
    
    return answer;
}