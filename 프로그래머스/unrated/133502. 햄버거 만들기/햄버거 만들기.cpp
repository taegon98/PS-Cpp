#include <string>
#include <vector>
#include <stack>
using namespace std;
stack<int> s;

bool check() {
    stack<int> temp;

    for (int i = 3; i >= 1; i--) {
        if (s.size() and s.top() == i) {
            temp.push(i);
            s.pop();
        }
        else break;
    }
    if (temp.size() == 3) return true;
    else {
        while (temp.size()) {
            s.push(temp.top());
            temp.pop();
        }
        return false;
    }
}

int solution(vector<int> ingredient) {
    int answer = 0;

    for (auto var : ingredient) {
        if (!s.empty() and (s.top() == 3 and var == 1)) {
            if (check()) {
                answer++;
                continue;
            }
        }
        s.push(var); 
    }
    return answer;
}